#include "protein_translation.h"


namespace protein_translation {

std::vector<std::string> proteins(std::string codons) {
    std::vector<std::string> result;
    static const std::unordered_map<std::string, std::string> codon_table {
        {"AUG", "Methionine"}, {"UUU", "Phenylalanine"}, {"UUC", "Phenylalanine"},
        {"UUA", "Leucine"}, {"UUG", "Leucine"}, {"UCU", "Serine"},
        {"UCC", "Serine"}, {"UCA", "Serine"}, {"UCG", "Serine"},
        {"UAU", "Tyrosine"}, {"UAC", "Tyrosine"}, {"UGU", "Cysteine"},
        {"UGC", "Cysteine"}, {"UGG", "Tryptophan"}, {"UAA", "STOP"},
        {"UAG", "STOP"}, {"UGA", "STOP"}
    };

    for (size_t i{0}; i < codons.length(); i += 3) {
        std::string codon = codons.substr(i, 3);
        auto it{codon_table.find(codon)};

        if (it == codon_table.end()) 
            break;
        if (it->second == "STOP")
            break;

        result.emplace_back(it->second);
    }

    return result;
}

}  // namespace protein_translation
