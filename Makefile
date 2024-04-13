all:
	g++ ans.cpp -o ans
	./ans < ./2.txt > out
	python3 checker.py 2.txt out