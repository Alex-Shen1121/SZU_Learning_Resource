# Initialization
import sys
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import scipy.optimize as opt
sys.path.append('../')
from costFunctionReg import costFunctionReg
from mapFeature import mapFeature
from plotData import plotData
from plotDecisionBoundary import plotDecisionBoundary
from predict import predict

# Load Data
#  The first two columns contains the X values and the third column
#  contains the label (y).

data = pd.read_csv('ex2data2.txt', header=None)
X = np.array(data.iloc[:, 0:2])
y = np.array(data.iloc[:, 2]).reshape(-1, 1)

ax = plotData(X, y)

# Labels and Legend
h, _ = ax.get_legend_handles_labels()
ax.set_xlabel('Microchip Test 1')
ax.set_ylabel('Microchip Test 2')
# Specified in plot order
ax.legend(h, ['y = 1', 'y = 0'])

plt.show()


# =========== Part 1: Regularized Logistic Regression ============
#  In this part, you are given a dataset with data points that are not
#  linearly separable. However, you would still like to use logistic
#  regression to classify the data points.
#
#  To do so, you introduce more features to use -- in particular, you add
#  polynomial features to our data matrix (similar to polynomial
#  regression).
#

# Add Polynomial Features

# Note that mapFeature also adds a column of ones for us, so the intercept
# term is handled
X = mapFeature(X[:, 0], X[:, 1])
print(X.shape)
print(y.shape)


# ============= Part 2: Regularization and Accuracies =============
#   Optional Exercise:
#   In this part, you will get to try different values of lambda and
#   see how regularization affects the decision coundart
#
#   Try the following values of lambda (0, 1, 10, 100).
#
#   How does the decision boundary change when you vary lambda? How does
#   the training set accuracy vary?
# Initialize fitting parameters
initial_theta = np.zeros((1, X.shape[1]))

# Set regularization parameter lambda to 1
_lambda = 1

# Compute and display initial cost and gradient for regularized logistic
# regression
cost, grad = costFunctionReg(initial_theta, X, y, _lambda)

print('Cost at initial theta (zeros): %.3f' % cost)
print('Expected cost (approx): 0.693')
print('Gradient at initial theta (zeros) - first five values only:\n')
print(np.around(grad[0, 0:5], decimals=4))
print('Expected gradients (approx) - first five values only:')
print(' 0.0085 0.0188 0.0001 0.0503 0.0115')

# Compute and display cost and gradient
# with all-ones theta and lambda = 10
test_theta = np.ones((1, X.shape[1]))
cost, grad = costFunctionReg(test_theta, X, y, 10)

print('\nCost at test theta (with lambda = 10): %.2f' % cost)
print('Expected cost (approx): 3.16')
print('Gradient at test theta - first five values only:')
print(np.around(grad[0, 0:5], decimals=4))
print('Expected gradients (approx) - first five values only:')
print(' 0.3460 0.1614 0.1948 0.2269 0.0922')



# Initialize fitting parameters
initial_theta = np.zeros((1, X.shape[1])).reshape(1, -1)

# Set regularization parameter lambda to 1 (you should vary this)
_lambda = 100  # 0过拟合，100欠拟合

# Optimize

theta, _, _ = opt.fmin_tnc(func=costFunctionReg, x0=initial_theta, args=(X, y, _lambda))

# Plot Boundary
ax = plotDecisionBoundary(theta, X, y)
plt.title('lambda = {:.2f}'.format(_lambda))

# Labels and Legend
ax.set_xlabel('Microchip Test 1')
ax.set_ylabel('Microchip Test 2')

h, _ = ax.get_legend_handles_labels()
ax.legend(h, ['y = 1', 'y = 0'])
plt.show()

# Compute accuracy on our training set
p = predict(theta, X)

print('Train Accuracy: %.1f' % (np.mean(p == y) * 100))
print('Expected accuracy (with lambda = 1): 83.1 (approx)')