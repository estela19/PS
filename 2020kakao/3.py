class Person:
    def __init__(self, str):
        self.list = []
        self.list = str.split(" ")



    def check(self, query):
        length = len(query) - 1
        print(query)
        print(self.list)
        for i in range(0, length):
            if (query[i] == '-'):
                pass
            elif query[i] != self.list[i]:
                return False

        if query[4] > self.list[4]:
            return False

        return True


def solution(info, query):
    answer = []
    inform = []


    for i in info:
        inform.append(Person(i))

    for i in query:
        cnt = 0
        q = i.split(" ")
        del q[5]
        del q[3]
        del q[1]

        for j in inform:
            if j.check(q):
                cnt = cnt + 1
                print(cnt)

        answer.append(cnt)
    print(answer)
    return answer

i = ["java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"]
qu = ["java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"]

solution(i, qu)