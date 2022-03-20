import subprocess

process = subprocess.Popen(
    'dir',
    stdout=subprocess.PIPE,
    stderr=subprocess.STDOUT,
    shell=True,
    #encoding='utf-8',
    errors='replace'
)
print("ddd")
while True:
    realtime_output = process.stdout.readline()

    if realtime_output == '' and process.poll() is not None:
        break

    if realtime_output:
        print(realtime_output.strip(), flush=True)