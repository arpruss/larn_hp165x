set -e
make -f Makefile.hp165x
cp d:/DSKA0010-BigSoft.HFE .
python ../../lifutils.py put DSKA0010-BigSoft.HFE ../loader/loader.bin SYSTEM_ C001
python ../../lifutils.py put DSKA0010-BigSoft.HFE larn.bin Larn.bin C001
python ../../lifutils.py mput DSKA0010-BigSoft.HFE larnmazefile larnforts 1
cp DSKA0010-BigSoft.HFE d:/