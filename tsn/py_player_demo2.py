from PyQt5.QtWidgets import *
from PyQt5.QtMultimedia import *
from PyQt5.QtGui import *
from PyQt5.QtCore import *
from PyQt5.QtMultimediaWidgets import QVideoWidget
from GUI import Ui_MainWindow
from myVideoWidget import myVideoWidget
import sys
import numpy as np
import time
class myMainWindow(Ui_MainWindow,QMainWindow):
    def __init__(self):
        super(Ui_MainWindow, self).__init__()
        self.setupUi(self)
        self.videoFullScreen = False   # 判断当前widget是否全屏
        self.videoFullScreenWidget = myVideoWidget()   # 创建一个全屏的widget
        self.videoFullScreenWidget.setFullScreen(1)
        self.videoFullScreenWidget.hide()               # 不用的时候隐藏起来
        self.player = QMediaPlayer()
        self.player.setVideoOutput(self.wgt_video)  # 视频播放输出的widget，就是上面定义的
        self.btn_open.clicked.connect(self.openVideoFile)   # 打开视频文件按钮
        self.btn_play.clicked.connect(self.playVideo)       # play
        self.btn_stop.clicked.connect(self.pauseVideo)       # pause
        self.player.positionChanged.connect(self.changeSlide)      # change Slide
        self.videoFullScreenWidget.doubleClickedItem.connect(self.videoDoubleClicked)  #双击响应
        self.wgt_video.doubleClickedItem.connect(self.videoDoubleClicked)   #双击响应
        self.videoname=''
        self.name = ''


    def openVideoFile(self):
        self.videoname  = QFileDialog.getOpenFileName()[0]
        print( self.videoname  )
        url = QUrl(self.videoname)
        self.player.setMedia(QMediaContent(url))  # 选取视频文件
        self.player.play()  # 播放视频
        i = self.videoname.rfind('/')
        j = self.videoname.rfind('.')
        self.name = self.videoname[i + 1:j]
        
        self.table = Table(Name=self.name)
        self.btn_detection.clicked.connect(self.table.handle_click)
    def playVideo(self):
        self.player.play()
    def pauseVideo(self):
        self.player.pause()
    def changeSlide(self,position):
        self.vidoeLength = self.player.duration()+0.1
        self.sld_video.setValue(round((position/self.vidoeLength)*100))
        self.lab_video.setText(str(round((position/self.vidoeLength)*100,2))+'%')
    def videoDoubleClicked(self,text):
        if self.player.duration() > 0:  # 开始播放后才允许进行全屏操作
            if self.videoFullScreen:
                self.player.pause()
                self.videoFullScreenWidget.hide()
                self.player.setVideoOutput(self.wgt_video)
                self.player.play()
                self.videoFullScreen = False
            else:
                self.player.pause()
                self.videoFullScreenWidget.show()
                self.player.setVideoOutput(self.videoFullScreenWidget)
                self.player.play()
                self.videoFullScreen = True



class Table(QWidget):
    def __init__(self,parent=None,Name=''):
        super(Table, self).__init__(parent)
        #设置标题与初始大小
        self.setWindowTitle('Detecting')
        self.resize(800,800)
        self.name = Name
        #设置数据层次结构，4行4列
        self.model=QStandardItemModel(6,1)
        #设置水平方向四个头标签文本内容
        self.model.setHorizontalHeaderLabels(['Scores/Result'])
        self.model.setVerticalHeaderLabels(['BabyCrawling','BaseballPitch','HammerThrow','SumoWrestling','Typing','Result'])
      #  dic = dict(zip(['BabyCrawling','BaseballPitch','HammerThrow','SumoWrestling','Typing'], [0, 1, 2,3,4]))
        dic = dict(zip(['3', '2', '5', '1', '4'], [0, 1, 2, 3, 4]))
        resdic = dict(zip( [0, 1, 2,3,4],['BabyCrawling','BaseballPitch','HammerThrow','SumoWrestling','Typing'],))






        labels = np.load(b'C:\Users\Krishlo\Desktop\labels.npy')
        scores = np.load(b'C:\Users\Krishlo\Desktop\scores.npy', allow_pickle=True)
        s = []
        f = np.zeros([5, 5])
        for i in range(0, 5):
            for label in labels:
                score = 0
                for j in range(0, 25):
                    score += scores[i][0][j][0][labels]
                score /= 25
            f[i] = score

     #   self.model.appendRow([
       #      QStandardItem('row %s,column %s' % (11,11)),
       #     QStandardItem('row %s,column %s' % (11,11)),
       #     QStandardItem('row %s,column %s' % (11,11)),
      #      QStandardItem('row %s,column %s' % (11,11)),
      #   ])
        res = np.argmax(f[dic[self.name]])
        for column in range(5):
            item=QStandardItem('%lf'%f[dic[self.name]][column])
                #设置每个位置的文本值
            self.model.setItem(column,0,item)
        self.model.setItem(5,0,QStandardItem(resdic[res]))
        #实例化表格视图，设置模型为自定义的模型
        self.tableView=QTableView()
        self.tableView.setModel(self.model)



        # todo 优化1 表格填满窗口
        # #水平方向标签拓展剩下的窗口部分，填满表格
        self.tableView.horizontalHeader().setStretchLastSection(True)
        # #水平方向，表格大小拓展到适当的尺寸
        self.tableView.horizontalHeader().setSectionResizeMode(QHeaderView.Stretch)
        #
        # #TODO 优化3 删除当前选中的数据
        # indexs=self.tableView.selectionModel().selection().indexes()
        # print(indexs)
        # if len(indexs)>0:
        #     index=indexs[0]
        #     self.model.removeRows(index.row(),1)


        #设置布局
        layout=QVBoxLayout()
        layout.addWidget(self.tableView)
        self.setLayout(layout)

    def handle_click(self):
            if not self.isVisible():
                time.sleep(1)
                self.show()

if __name__ == '__main__':

    app = QApplication(sys.argv)
    vieo_gui = myMainWindow()
 #   table = Table()
 #   vieo_gui.btn_detection.clicked.connect(table.handle_click)
    vieo_gui.show()
    sys.exit(app.exec_())