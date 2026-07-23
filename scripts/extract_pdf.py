"""Extract text from a contest PDF into a .txt file next to it.

Usage: python3 scripts/extract_pdf.py contests/ccsce/2024/ccsce2024-contest.pdf
"""
import sys
from pathlib import Path
from PyPDF2 import PdfReader

if len(sys.argv) != 2:
    print(__doc__.strip(), file=sys.stderr)
    sys.exit(1)

pdf_path = Path(sys.argv[1])
if not pdf_path.exists():
    print('PDF not found:', pdf_path, file=sys.stderr)
    sys.exit(1)

reader = PdfReader(str(pdf_path))
text = []
for p in reader.pages:
    text.append(p.extract_text() or '')

out = pdf_path.with_suffix('.txt')
out.write_text('\n\n'.join(text), encoding='utf-8')
print('Wrote', out)
