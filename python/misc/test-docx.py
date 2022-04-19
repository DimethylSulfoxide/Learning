from docx import Document
from docx.shared import Cm
doc = Document()
doc.add_picture('./test.png', width = Cm(8.2))
doc.save('./test.docx')
