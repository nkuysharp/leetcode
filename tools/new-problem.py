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
MAKE_FILE_TEMPLATE = os.path.join(TOOL_DIR, "templates/makefile.template")
CPP_MAKE_FILE_SECTION = os.path.join(TOOL_DIR, "templates/make.c++.section.template")
JS_MAKE_FILE_SECTION = os.path.join(TOOL_DIR, "templates/make.js.section.template")
PROBLEM_ROOT_DIR = "./"
SUPPORTED_LANGUAGES = ['c++', 'js']

TEMPLATE_TABLE = {'c++':{'src_template':CPP_SRC_TEMPLATE,
                         'main_template':CPP_MAIN_TEMPLATE,
                         'src_suffix':'h',
                         'main_suffix':'cpp',
                         'make_section':CPP_MAKE_FILE_SECTION,
                         'target-key':'CPP_TARGET',
                         'section-key':'CPP_SECTION'},
                  'js':{'src_template':JS_SRC_TEMPLATE,
                        'main_template':JS_MAIN_TEMPLATE,
                        'src_suffix':'js',
                        'main_suffix':'js',
                        'make_section':JS_MAKE_FILE_SECTION,
                        'target-key':'JS_TARGET',
                        'section-key':'JS_SECTION'},
                  'makefile':MAKE_FILE_TEMPLATE}


TEMPLATE_VALUES = {TEMPLATE_TABLE['c++']['section-key']:'',
                   TEMPLATE_TABLE['c++']['target-key']:'',
                   TEMPLATE_TABLE['js']['section-key']:'',
                   TEMPLATE_TABLE['js']['target-key']:''}




def Usage():
    print "Usage:"
    print "python %s (problem-name) [languages]"%(sys.argv[0])
    print "Options:"
    print "problem-name: \t\t\tSpecify Problem name"
    print "languages: \t\t\tSpecify languages to use. e.g. 'c++', 'c++,js'"


def CamelCase(problem_name):
    return ''.join(problem_name.title().split())
    
def GenerateSrcFromTemplates(src_template,
                             main_template,
                             prob_dir,
                             problem_name,
                             src_file_suffix,
                             main_file_suffix):

    src_filename = os.path.join(prob_dir, "%s.%s"%(CamelCase(problem_name), src_file_suffix))
    main_filename = os.path.join(prob_dir, "main.%s"%(main_file_suffix))

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
        
        
def GenerateSrcFiles(prob_dir, prob_name, lang_list):
    for lang in lang_list:
        if lang not in SUPPORTED_LANGUAGES:
            raise RuntimeError("Unsupported language type [%s]"%(lang))

        src_template = TEMPLATE_TABLE[lang]['src_template']
        main_template = TEMPLATE_TABLE[lang]['main_template']
        src_suffix = TEMPLATE_TABLE[lang]['src_suffix']
        main_suffix = TEMPLATE_TABLE[lang]['main_suffix']

        GenerateSrcFromTemplates(src_template,
                                 main_template,
                                 prob_dir,
                                 prob_name,
                                 src_suffix,
                                 main_suffix)

def GenerateLangSection(problem_name, lang):
    dirname = os.path.abspath(os.path.join(PROBLEM_ROOT_DIR, problem_name.title()))
    src_filename = "%s.%s"%(CamelCase(problem_name), TEMPLATE_TABLE[lang]['src_suffix'])
    main_filename = "main.%s"%(TEMPLATE_TABLE[lang]['main_suffix'])
    with open(TEMPLATE_TABLE[lang]['make_section'], "r") as infile:
        values = {}
        values['SRC_FILENAME'] = src_filename
        values['MAIN_FILENAME'] = main_filename
        values[TEMPLATE_TABLE[lang]['target-key']] = "run-%s.exe"%(lang)
        file_template = string.Template(infile.read())
        return file_template.substitute(values)
        
def GenerateMakeFile(prob_dir, problem_name, lang_list):
    for lang in lang_list:
        if lang not in SUPPORTED_LANGUAGES:
            raise RuntimeError("Unsupported language type [%s]"%(lang))

    mk_file_name = os.path.join(prob_dir, "makefile")
    with open(mk_file_name, "w") as outfile, open(TEMPLATE_TABLE['makefile'], 'r') as infile:
        for lang in lang_list:
            TEMPLATE_VALUES[TEMPLATE_TABLE[lang]['target-key']] = "run-%s.exe"%(lang)
            TEMPLATE_VALUES[TEMPLATE_TABLE[lang]['section-key']] = GenerateLangSection(problem_name, lang)

        file_template = string.Template(infile.read())
        outfile.write(file_template.substitute(TEMPLATE_VALUES))
        print "[info] file: %s is generated."%(mk_file_name)

def CreateProblemDirectory(prob_name):
    dirname = '_'.join(prob_name.title().split())
    prob_dir = os.path.abspath(os.path.join(PROBLEM_ROOT_DIR, dirname))
    if (os.path.exists(dirname)):
        raise RuntimeError("Problem[%s] already exists."%(prob_name))
    else:
        os.makedirs(prob_dir)
        print "created directory [%s]"%(dirname)
        return prob_dir

if __name__ == "__main__":
    if(len(sys.argv) < 2):
        Usage()
        exit()

    prob_name = sys.argv[1]
    lang_list = ['c++']
    if (len(sys.argv) > 2):
        lang_list = sys.argv[2].split(',')
        lang_list = [lang.strip() for lang in lang_list]
    
    problem_dir = CreateProblemDirectory(prob_name)
    GenerateSrcFiles(problem_dir, prob_name, lang_list)
    GenerateMakeFile(problem_dir, prob_name, lang_list)
    
    
