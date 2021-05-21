import sys

class Reader:
    @classmethod
    def readline(self):
        return sys.stdin.readline()
    
    @classmethod
    def readline_split(self, func = None):
        if func:
            return map(func, sys.stdin.readline().split())
        else: 
            return sys.stdin.readline().split()
    
    @classmethod
    def readline_list(self, func):
        return list(self.readline_split(func))
        
if __name__ == '__main__':
    
    