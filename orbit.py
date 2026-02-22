import pandas as pd
import matplotlib.pyplot as plt 
import numpy as np
df = pd.read_csv("orbit.csv")
x = df["x"]
y = df["y"]
z = df["z"]
earth_r = 6371000
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

u, v = np.mgrid[0:2*np.pi:50j, 0:np.pi:25j] 
xs = earth_r * np.cos(u) * np.sin(v) 
ys = earth_r * np.sin(u) * np.sin(v) 
zs = earth_r * np.cos(v) 
ax.plot_surface(xs, ys, zs, color='blue', alpha=1, label="Earth")

max_range = max(
        max(abs(x)),
        max(abs(y)),
        max(abs(z)),
        earth_r * 1.2 
        )
ax.set_xlim(-max_range, max_range)
ax.set_ylim(-max_range, max_range)
ax.set_zlim(-max_range, max_range)

ax.set_xlabel("X (m)")
ax.set_ylabel("Y (m)")
ax.set_zlabel("Z (m)")
ax.set_title("Satellite Orbit")
trail, = ax.plot([], [], "g--")
satellite, = ax.plot([], [], "ro")

for i in range (len(x)):
    trail.set_data(x[:i], y[:i])
    trail.set_3d_properties(z[:i])
    satellite.set_data([x[i]], [y[i]])
    satellite.set_3d_properties([z[i]])
    plt.draw()
    plt.pause(0.001)
plt.ioff()
plt.show()
