#include <iostream>
#include <fstream>
#include <cstring>

void makeTh14Th24Surface(std::string list) {
	std::string filePath;
	std::ifstream listFile(list.cstr());
	TGraph2D* chi2surface = new TGraph2D();
	while (listFile >> filePath) {
		TFile* inroot = new TFile(filePath.c_str(), "READ");
		TGraph2D* tmp_gr = (TGraph2D*) inroot->Get("Chi2");
		double ssqth14, ssqth24, chi2;
		tmp_gr->GetPoint(0, ssqth14, ssqth24, chi2);
		chi2surface->SetPoint(chi2surface->GetN(), ssqth14, ssqth24, chi2);
		inroot->Close();
	}
}
