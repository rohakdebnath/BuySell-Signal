READ THIS CAREFULLY

Code SPECIFICALLY DESGINED FOR CLANG++. DO NOT IGNORE the "tasks.json" file in ".vscode", Install cURL and jsoncpp packages using homebrew, locate them using terminal with the following:
1. type "mdfind -name "{fileName}" on Terminal
2. make sure that json.h and curl.h are available in the include PATH of your compiler (I made this for Clang++)
3. clang -E -x c++ - -v < /dev/null [use this command on a terminal to figure out all the include PATHS clang looks for]
4. Use ChatGPT to describe your compiler problems, 9 times out of 10 it solves your problem if you describe it properly

YOU MAY NEED TO COMPLETELY CHANGE THE TASKS.JSON file to match you Mac Setup if you fiddle with directories.

Input a ticker symbol and it gives advice on buy or sell. The advice is extremely basic and honestly shit, but that's because the purpose of this program is to explore cURL and JsonCpp.
This program is inspired from https://github.com/OpenGenus/trading-app-in-cpp. Although the basic idea matches, I have heavily optimized the content of the code, written 
by me on my mac, added several features and planning to make it much more robust. 

