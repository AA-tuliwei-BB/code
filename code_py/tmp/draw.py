#!/usr/bin/python3

import matplotlib.pyplot as plt
import numpy as np

# x = [0, 5, 10, 15, 20, 25]
# y = [2.96, 4.13, 4.62, 5.03, 5.80, 11.57]

x = [0, 2, 4, 8, 10, 20, 28.78]
y = [3.52, 3.67, 4.04, 4.40, 4.55, 5.44, 10.70]
z = [3.38, 3.78, 4.05, 4.43, 4.58, 5.36, 10.66]

from scipy.interpolate import make_interp_spline

import mpl_toolkits.axisartist as axisartist
fig = plt.figure(figsize=(8, 16)) #使用axisartist.Subplot方法创建一个绘图区对象ax 
ax = axisartist.Subplot(fig, 111)  #将绘图区对象添加到画布中
fig.add_axes(ax)

#通过set_visible方法设置绘图区所有坐标轴隐藏
ax.axis[:].set_visible(False)

#ax.new_floating_axis代表添加新的坐标轴
ax.axis["x"] = ax.new_floating_axis(0,0)
#给x坐标轴加上箭头
ax.axis["x"].set_axisline_style("->", size = 1.0)
#添加y坐标轴，且加上箭头
ax.axis["y"] = ax.new_floating_axis(1,0)
ax.axis["y"].set_axisline_style("-|>", size = 1.0)
#设置x、y轴上刻度显示方向
ax.axis["x"].set_axis_direction("bottom")
ax.axis["y"].set_axis_direction("left")

x_new = np.linspace(min(x),max(x),50)
y_smooth = make_interp_spline(x, y)(x_new)
z_smooth = make_interp_spline(x, z)(x_new)
plt.axis([0,29,0,14])
plt.plot(x_new, y_smooth, label = 'Observated')
plt.plot(x_new, z_smooth, label = 'Calculated')
plt.legend(loc='upper right')
plt.show()
