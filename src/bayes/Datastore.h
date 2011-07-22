#include <vector>
#include <string>
using namespace std;
namespace cmahout
{
	class Datastore
	{
		public:
			virtual ~Datastore() = 0 {}
			virtual double getWeight(string matrixName, string row, string, column);
			virtual double getWeight(string vectorName, string index);
			virtual vector<string> getKeys(string name);
			virtual initialize();
	};
