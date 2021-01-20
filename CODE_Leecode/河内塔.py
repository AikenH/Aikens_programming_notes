'''
Aiken
通过河内塔来训练一下递归的思考方式（习惯或者说了解这种编程方式）
'''

def move(begin='begin',final='final'):
    print("move from {} ot {}".format(begin,final))

def solution(num,begin,temp,final):
    # 确定初始条件
    if num ==1:
        move(begin,final)
    # 确定基于可完成行假设来实现递归步骤
    else:
        solution(num-1,begin,final,temp)
        move(begin,final)
        solution(num-1,temp,begin,final)

if __name__ == "__main__":
    solution(7,'A','B','C')
    pass