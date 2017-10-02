import matplotlib.pyplot as plt
import matplotlib.axis

filnames=['build-1a-Desktop-Debug/V1_n_300.txt','build-1a-Desktop-Debug/V2_w_001_n_300.txt','build-1a-Desktop-Debug/V2_w_05_n_300.txt','build-1a-Desktop-Debug/V2_w_1_n_300.txt','build-1a-Desktop-Debug/V2_w_5_n_300.txt']

def leser(filename):
	with open(filename) as f:
	    lines = f.readlines()
	    x1 = [line.split()[1] for line in lines]
	    x2 = [line.split()[3] for line in lines]
	    x3 = [line.split()[5] for line in lines]
	    rho= [line.split()[7] for line in lines]

	return x1,x2,x3, rho

V1_x1,V1_x2,V1_x3,V1_rho=leser(filnames[0])
V2_w_001_x1,V2_w_001_x2,V2_w_001_x3,V2_w_001_rho=leser(filnames[1])
V2_w_05_x1,V2_w_05_x2,V2_w_05_x3,V2_w_05_rho=leser(filnames[2])
V2_w_1_x1,V2_w_1_x2,V2_w_1_x3,V2_w_1_rho=leser(filnames[3])
V2_w_5_x1,V2_w_5_x2,V2_w_5_x3,V2_w_5_rho=leser(filnames[4])


ax1=plt.plot(V1_rho,V1_x1)
plt.ylabel("u")

plt.xlabel(r'$ \rho $')
plt.title( "Non-interacting potential")
plt.plot(V1_rho,V1_x2)
plt.plot(V1_rho,V1_x3)
plt.show()
ax2=plt.subplot(4,1,1, title="omega=0.001", ylabel="u")
plt.plot(V2_w_001_rho,V2_w_001_x1)
plt.plot(V2_w_001_rho,V2_w_001_x2)
plt.plot(V2_w_001_rho,V2_w_001_x3)
plt.yticks([-0.2,0,0.2])

ax3=plt.subplot(4,1,2, sharey=ax2, title="omega=0.5", ylabel="u" )
plt.plot(V2_w_05_rho,V2_w_05_x1)
plt.plot(V2_w_05_rho,V2_w_05_x2)
plt.plot(V2_w_05_rho,V2_w_05_x3)


ax4=plt.subplot(4,1,3, sharey=ax2, title="omega=1", ylabel="u")

plt.plot(V2_w_1_rho,V2_w_1_x1)
plt.plot(V2_w_1_rho,V2_w_1_x2)
plt.plot(V2_w_1_rho,V2_w_1_x3)

ax5=plt.subplot(4,1,4, sharey=ax2, title="omega=5", ylabel="u", xlabel=r'$ \rho $')
plt.plot(V2_w_5_rho,V2_w_5_x1)
plt.plot(V2_w_5_rho,V2_w_5_x2)
plt.plot(V2_w_5_rho,V2_w_5_x3)

plt.show()



