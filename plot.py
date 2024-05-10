import matplotlib as mpl
import matplotlib.pyplot as plt
import numpy as np
import csv

import os

data = []

with open("data\\20240505202222.csv", newline='') as f:
    r = csv.reader(f)
    for row in r:
        entry = row[0].strip()
        if entry:
            entry = int(entry)
            data.append(entry)

print(data)

fig, ax = plt.subplots()  # Create a figure containing a single axes.
ax.plot(data, c='hotpink', alpha=1.0)  # Plot some data on the axes.

plt.xlabel("n")
plt.ylabel("emg")
plt.title("EMG Graph")
plt.show()