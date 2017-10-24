import numpy as np
from sklearn.naive_bayes import GaussianNB

x = np.array([[-1, -1], [-2, -1], [-3, -2], [1, 1], [2, 1], [3, 2]])
y = np.array([1, 1, 1, 2, 2, 2])

clf = GaussianNB()
print(clf.predict([[-0.8, -1]]))
clf_pf = GaussianNB()
clf_pf.partial_fit(x, y, np.unique(y))
print(clf_pf.predict([[-0.8, -1]]))
