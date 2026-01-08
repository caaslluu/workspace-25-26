import sys

def rot13(s):
    result = ""
    for c in s:
        if 'a' <= c <= 'z':
            result += chr((ord(c) - ord('a') + 13) % 26 + ord('a'))
        elif 'A' <= c <= 'Z':
            result += chr((ord(c) - ord('A') + 13) % 26 + ord('A'))
        else:
            result += c
    return result

if len(sys.argv) < 2:
    sys.exit(1)

if __name__=="__main__":
    message = sys.argv[1]
    print(rot13(message))

