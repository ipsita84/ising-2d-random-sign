import matplotlib.pyplot as plt #import this to make plots

#specify fonts for plots and enable using Latex:
from matplotlib import rc
rc('font',**{'family':'serif','serif':['Computer Modern']})
rc('text', usetex=True)


N = 2 # number of files to print (i.e. number of disorder realizations)

for i in range(N):
  dirName = 'Disorder_' + str(i) # name of the folder storing information about the i^th 
                                 # disorder realization (change name to whatever you have named
                                 # these folders)
  fileName = dirName + '/E.dat'
  fin = open(fileName, 'r')
  beta_list  = []
  EAvg_list  = []
  
  #Loop through all lines of the file:
  for line in fin:
    beta,EAvg = line.split()
    beta_list.append(float(beta))
    EAvg_list.append(float(EAvg))

  plt.plot(beta_list, EAvg_list, label='DR ' + str(i))

#Label the plot:
plt.xlabel(r'$\beta$', fontsize=20)              #label for the x-axis
plt.ylabel(r'$\langle E \rangle$', fontsize=20)  #label for the y-axis
plt.legend(prop={'size':16},loc='lower right')   #info about legend

#Save the plot as a pdf:
plt.savefig('EVsBeta.pdf',bbox_inches='tight')

#Display the plot:
plt.show()