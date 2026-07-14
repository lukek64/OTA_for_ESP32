import shutil
import sys
from pathlib import Path
import subprocess

project_name = sys.argv[1]

template = Path(__file__).resolve().parents[1]      # ESP32-Template
projects = template.parent                          # Projects folder

destination = projects / project_name

if destination.exists():
    print(f"{project_name} already exists!")
    sys.exit(1)

shutil.copytree(template, destination)

# Remove the tools folder from the new project if you don't want it copied
# shutil.rmtree(destination / "tools")

print(f"Created {destination}")

# Open the new project in VS Code
subprocess.Popen([
    r"C:\Users\luke1\AppData\Local\Programs\Microsoft VS Code\Code.exe",
    str(destination)
])
