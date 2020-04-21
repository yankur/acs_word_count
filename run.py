import sys
import subprocess
import matplotlib.pyplot as plt


def main(n):
    min_time = 1000000
    time = []
    for threads in range(1, n):
        generate_config(threads)
        out = subprocess.Popen(['./lab4_word_count'],
                               stdout=subprocess.PIPE,
                               stderr=subprocess.STDOUT)
        stdout, stderr = out.communicate()
        min_time = min(int(stdout.split()[-1]), min_time)
        time.append(int(stdout.split()[-1]))
    generate_graph(n, time)
    print('Minimal time: ', min_time)


def test(threads):
    generate_config(threads)
    out = subprocess.Popen(['./lab4_word_count', 'config.dat'],
                           stdout=subprocess.PIPE,
                           stderr=subprocess.STDOUT)
    stdout, stderr = out.communicate()


def generate_config(threads):
    conf_file = open('config.dat', 'w')
    conf_file.write('infile=\"bible.txt\"\nout_by_a=\"res_a.txt\"\nout_by_n=\"res_n.txt\"\nthreads={}'.format(threads))
    conf_file.close()


def generate_graph(threads, time):
    threads = [_ for _ in range(1, threads + 1)]
    plt.plot(threads, time)
    plt.xlabel('n of threads')
    plt.ylabel('time ms')
    plt.savefig('time_vs_threads_graph.png')


if sys.argv[1] != 'test':
    main(int(sys.argv[1]))
else:
    test(sys.argv[2])
