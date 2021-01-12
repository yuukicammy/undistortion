import glob
import argparse


def get_jpeg_path(dir):
    files = glob.glob(dir+'/*.jpeg')
    for file in files:
        print(file)
    return files


def create_xml_file(files, output_filename):
    with open(output_filename, mode='w') as f:
        f.write('<?xml version="1.0"?>\n')
        f.write('<opencv_storage>\n')
        f.write('<images>\n')
        for file in files:
            f.write(file + '\n')
        f.write('</images>\n')
        f.write('</opencv_storage>\n')


if __name__ == '__main__':
    parser = argparse.ArgumentParser(
        description='This program creates a XML file that lists a path to use camera calibration.')
    parser.add_argument(
        'dir', help='The directory path that contains input JPEG images.')
    parser.add_argument(
        'out', help='The output XML file path.')
    args = parser.parse_args()
    files = get_jpeg_path(args.dir)
    create_xml_file(files, args.out)
