import re

def solution(new_id):
    id = new_id

    #step 1
    id = id.lower()
    print(id)

    #step 2
    for char in '~!@#$%^&*()=+[{]}:?,<>':
        id = id.replace(char, '')
    print(id)

    if len(id) != 0:
        #step 3, 4
        nid = ""
        if(id[0] == '.'):
            nid += "@"
        else:
            nid += id[0]

        length = len(id)
        for i in range(1, length):
           if not(id[i] == '.' and id[i - 1] == '.') :
               nid += id[i]

        if(nid[len(nid) - 1] == '.'):
            nid = nid[:len(nid) - 1]

        nid = nid.replace('@','')
        id = nid
        print(id)

    #step 5
    if(id == ""):
        id += "a"

    #step 6
    if(len(id) > 15):
        id = id[:15]

    if (id[len(id) - 1] == '.'):
        id = id[:len(id) - 1]


    print(id)

    idx = len(id)
    #step 7
    while( idx < 3):
        id += id[-1]
        idx += 1
    print(id)

    return id
    #~!@#$%^&*()=+[{]}:?,<>


solution("!A.")