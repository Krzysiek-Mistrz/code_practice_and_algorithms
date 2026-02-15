#include <iostream>
#include <cmath>
#include <climits>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int minDiff = INT_MAX;
    TreeNode* prev = nullptr;

    int getMinimumDifference(TreeNode* root) {
        inOrder(root);
        return minDiff;
    }

    void inOrder(TreeNode* node) {
        if (node == nullptr) return;

        inOrder(node->left);

        if (prev != nullptr) {
            minDiff = std::min(minDiff, node->val - prev->val);
        }
        prev = node;

        inOrder(node->right);
    }
};

/*
Wyobraźmy sobie drzewo:

    4
   / \
  2   6

    Start: Wywołujesz inOrder(4).

        Funkcja inOrder(4) najpierw mówi: „Zanim cokolwiek zrobię, muszę sprawdzić moje lewe dziecko”. Wywołuje więc inOrder(2).

    W lewej gałęzi: inOrder(2) mówi to samo: „Muszę sprawdzić lewe dziecko”. Wywołuje inOrder(nullptr).

        inOrder(nullptr) od razu wraca (return), nic nie robiąc.

    Akcja dla 2: Teraz inOrder(2) wykonuje swój drugi krok (akcję):

        Sprawdza prev. Ponieważ to pierwszy węzeł, prev jest nullptr. Nic nie liczy.

        Ustawia prev = 2.

    W prawo od 2: inOrder(2) wywołuje swoje prawe dziecko: inOrder(nullptr), które nic nie robi.

    Powrót do 4: Funkcja dla węzła 2 skończyła pracę. Wracamy do inOrder(4), który właśnie skończył swój pierwszy krok (lewo).

        Akcja dla 4: Sprawdza różnicę między obecnym węzłem (4) a prev (2).

        4 - 2 = 2. Zapisujemy to jako nasze minDiff.

        Ustawia prev = 4.

    W prawo od 4: Teraz inOrder(4) robi swój trzeci krok i wywołuje inOrder(6).

        inOrder(6) najpierw wywołuje lewe dziecko (nic tam nie ma).

        Akcja dla 6: Sprawdza różnicę między obecnym (6) a prev (4).

        6 - 4 = 2. Porównuje z obecnym minDiff (nadal zostaje 2).

        Ustawia prev = 6.

        Wywołuje prawe dziecko (nic tam nie ma).

Jak to wygląda na stosie wywołań?

W pamięci komputera tworzy się „stos”. Funkcje czekają na siebie nawzajem:

    inOrder(4) czeka na inOrder(2)

    inOrder(2) czeka na swoje lewe nullptr

    Dopiero gdy lewa strona „odpuści” (dojdzie do końca), funkcja wraca i wykonuje obliczenia dla danego węzła.
*/