#include <iostream>
#include <map>
#include <vector>
using namespace std;

class versionManager
{
    int curVersion;
    map<string, int> featureToVersion;

public:
    versionManager()
    {
        curVersion = 1;
        // take input for initial features;
        string feature;
        while (cin >> feature)
        {
            if (feature[0] == '[')
            {
                feature.erase(feature.begin());
            }
            char en = feature.back();
            feature.pop_back();
            featureToVersion[feature] = curVersion;
            if (en == ']')
                break;
        }
    }

    void addFetaure(string feature)
    {
        curVersion++;
        featureToVersion[feature] = curVersion;
    }

    void modifyFeature(string oldFeature, string newFeature)
    {
        curVersion++;
        featureToVersion[oldFeature] = -1;
        featureToVersion[newFeature] = curVersion;
    }

    void checkFeature(int version, string feature)
    {
        if (featureToVersion.find(feature) != featureToVersion.end())
        {
            if (featureToVersion[feature] <= version and featureToVersion[feature] != -1)
            {
                cout << "yes\n";
                return;
            }
        }
        cout << "no\n";
    }
};

int main()
{
    versionManager vm = versionManager();
    string op;
    while (cin >> op)
    {
        if (op == "Add")
        {
            string feature;
            cin >> feature;
            vm.addFetaure(feature);
        }
        else if (op == "Modify")
        {
            string oldFeature, newFeature;
            cin >> oldFeature >> newFeature;
            vm.modifyFeature(oldFeature, newFeature);
        }
        else
        {
            string ver, feature;
            cin >> ver >> feature;
            int tem = 0;
            while ('0' <= ver.back() and ver.back() <= '9')
            {
                tem *= 10;
                tem += (ver.back() - '0');
                ver.pop_back();
            }
            int version = 0;
            while (tem)
            {
                version *= 10;
                version += (tem % 10);
                tem /= 10;
            }
            vm.checkFeature(version, feature);
        }
    }
    return 0;
}
