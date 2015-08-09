#! /usr/bin/python

import sys
import string
import exceptions
import os


TOOL_DIR = os.path.dirname(os.path.abspath(__file__))
CPP_SRC_TEMPLATE = os.path.join(TOOL_DIR, "templates/c++.src.template")
CPP_MAIN_TEMPLATE = os.path.join(TOOL_DIR, "templates/c++.main.template")
JS_SRC_TEMPLATE = os.path.join(TOOL_DIR, "templates/js.src.template")
JS_MAIN_TEMPLATE = os.path.join(TOOL_DIR, "templates/js.main.template")
MAKE_FILE_TEMPLTE = os.path.join(TOOL_DIR, "templates/makefile.template")
PROBLEM_ROOT_DIR = "./"



def Usage():
    print "Usage:"
    print "python %s (problem-name)"%(sys.argv[0])


def CamelCase(problem_name):
    return ''.join(problem_name.title().split())



    
def GenerateSrcFromTemplates(src_template,
                             main_template,
                             problem_name,
                             src_file_suffix,
                             main_file_suffix):

    dirname = os.path.abspath(os.path.join(PROBLEM_ROOT_DIR, problem_name.title()))
    src_filename = os.path.join(dirname, "%s.%s"%(CamelCase(problem_name), src_file_suffix))
    main_filename = os.path.join(dirname, "main.%s"%(main_file_suffix))

    with open(src_template, "r") as infile, open(src_filename, "w") as outfile:
        values = {}
        values['PROBLEM'] = ''.join(problem_name.split()).upper()
        file_template = string.Template(infile.read())
        outfile.write(file_template.substitute(values))

    with open(main_template, "r") as infile, open(main_filename, "w") as outfile:
        values = {}
        values['SOLUTION'] = os.path.basename(src_filename)
        file_template = string.Template(infile.read())
        outfile.write(file_template.substitute(values))

    print "[info] file: %s is generated."%(src_filename)
    print "[info] file: %s is generated."%(main_filename)
        
        
def GenerateSrcFiles(prob_name, lang='c++'):
    src_template = ''
    main_template = ''
    src_suffix = ''
    main_suffix = ''
    if (lang == 'c++'):
        src_template  = CPP_SRC_TEMPLATE
        main_template = CPP_MAIN_TEMPLATE
        src_suffix = "h"
        main_suffix = "cpp"
    elif lang == 'js':
        src_template = JS_SRC_TEMPLATE
        main_tempalte = JS_MAIN_TEMPLATE
        src_suffix = "js"
        main_suffix = "js"
    else:
        raise RuntimeError("Unsupported language type [%s]"%(lang))

    GenerateSrcFromTemplates(src_template,
                             main_template,
                             prob_name,
                             src_suffix,
                             main_suffix)

def CreateProblemDirectory(prob_name):
    dirname = os.path.abspath(os.path.join(PROBLEM_ROOT_DIR, prob_name.title()))
    if (os.path.exists(dirname)):
        raise RuntimeError("Problem[%s] already exists."%(prob_name))
    else:
        os.makedirs(dirname)
        print "created directory [%s]"%(dirname)

if __name__ == "__main__":
    if(len(sys.argv) < 2):
        Usage()
        exit()

    prob_name = sys.argv[1]
    dirname = CreateProblemDirectory(prob_name)
    GenerateSrcFiles(prob_name, 'c++')
    #GenerateMakeFile(dirname, prob_name)
    
    
    

        
