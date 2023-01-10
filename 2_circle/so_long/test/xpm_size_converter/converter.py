path = "../assets/"
filename = "item_3.xpm"
newfilename = "item_3.xpm"

pixel_from = 16
pixel_to = 32
colors = 0

with open(path + filename, "r") as f:
	before = f.read().split("\n")

colors = int(before[3].split(" ")[2])
after = before[:5 + colors]
after[3] = after[3].replace(str(pixel_from), str(pixel_to), 2)

for line in range(5 + colors, 5 + colors + pixel_from):
	newline = ""
	for letter in before[line][1:1 + pixel_from]:
		newline += letter + letter
	after.append('"' + newline + '",')
	after.append('"' + newline + '",')

after += before[5 + colors + pixel_from:]

for line in range(len(after) - 1):
	after[line] += "\n"

with open(path + newfilename, "w") as f:
	f.writelines(after)