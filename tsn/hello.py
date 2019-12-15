import numpy as np
labels = np.load(b'C:\Users\Krishlo\Desktop\labels.npy')
print(labels)

scores = np.load(b'C:\Users\Krishlo\Desktop\scores.npy',allow_pickle = True)
s=[]
f=np.zeros([5,5])
for i in range(0,5):
    for label in labels:
            score = 0
            for j in range(0,25):
                score += scores[i][0][j][0][labels]
            score/=25
    f[i]=score
print(f)

