import json
from os import write
import sys
import shutil
with open("leetcode.json") as f:
    leetcode = json.loads(f.read())


def get_question_filename(id):
    print(str(id))
    titleSlug = leetcode['data']['problemsetQuestionList']['questions'][id+1]['titleSlug']
    print(titleSlug)
    return str(id) + "_" + titleSlug + ".cpp"


id = int(sys.argv[1])
filename = get_question_filename(id)
# shutil.move("leetcode/{}.cpp".format(id),
#             "leetcode/{}".format(get_question_filename(id)))

template = '''
#include <cmath>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
'''
with open("leetcode/{}".format(get_question_filename(id)), 'w') as f:
    f.write(template)
