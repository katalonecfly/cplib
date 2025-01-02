# This script generates snippets for Sublime Text in 'SNIPPET_DIR' folder.
# Copy them to /path/to/sublime/.../Packages/User

import os
import sys
from string import Template 
from pathlib import Path


SNIPPET_DIR = 'snippets'
SNIPPET_EXTENSION = 'sublime-snippet'
SNIPPET_TEMPLATE = Template(
"""<snippet>
    <content><![CDATA[
$data
]]></content>
    <tabTrigger>$trigger</tabTrigger>
</snippet>"""
)


def gen():
  snippets = {}
  for root, dirs, files in os.walk('.'):
    if root in {'.', '.\\test', '.\\test\\custom'} or '.\\.git' in root:
      continue
    for filename in files:
      print(filename.split('.'))
      name, extension = filename.split('.')
      if extension not in {'hpp', 'cpp'}:
        continue

      if name in snippets:
        print(f'duplicate snippet name = {name}', file=sys.stderr)
        exit(0)

      path = root + '/' + filename
      data = Path(path).read_text()
      data = data.replace('#pragma once', '').strip()

      snippet = SNIPPET_TEMPLATE.substitute(
        data=data, 
        trigger=name,
      )
      
      snippets[name] = snippet
      print(f'generated snippet name = {name}', file=sys.stderr)  

  save(snippets)   


def save(snippets):
  for name, snippet in snippets.items():
    path = SNIPPET_DIR + '/' + name + '.' + SNIPPET_EXTENSION
    filepath = Path(path)
    filepath.parent.mkdir(parents=True, exist_ok=True)
    with filepath.open("w", encoding ="utf-8") as f:
      f.write(snippet)
  
  print(f'finished', file=sys.stderr)


if __name__ == "__main__":
  gen()