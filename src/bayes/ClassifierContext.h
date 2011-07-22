/**
*
* @author liuyizhe  zhe.liuyz@alibaba-inc.com or lyz10mars@gmail.com
*
* @wangwang liuyizhe10
*
* @last modified: 2011-07-22 14:22
*
* @file  ClassifierContext.h
*
* @brief This class is implemented the same as mahout ClassifierContext class for easy understanding 
*
* @details this is a header file with all function implementions, inline by default
*/
#include "ClassifierResult.h"
#include "Alogrithm.h"
#include "DataStore.h"

using namespace std;
namespace cmahout
{
	/**
	 * @brief The Classifier warpper used for choosing the @Algorithm and @Datastore
	 *
	 */
	class ClassifierContext
	{

		private:
			Algorithm *algorithm;
			Datastore *datastore;

		public:
			ClassifierContext(Algorithm *algorithm, Datastore *datastore)
			{
				this->alogrithm = algorithm;
				this->datastore = datastore;
			}

			/**
			 * @brief Initializes the Context. Gets the necessary data and check if the Datastore is valid
			 *
			 */
			void initialize()
			{
				datastore->initialize();
				algorithm->initialize(this->datastore);
			}

			/**
			 * @brief Classify the document and return the Result
			 *
			 * @param document the document to classify
			 * @param defaultCategory the default category to assign. Ties are broken by comparing the category
			 * @return A classify result
			 */
			ClassifierResult classifyDocument(vector<string> &document, string &defaultCategory)
			{
				algorithm->classifyDocument(document, datastore, defaultCategory);
			}

			/**
			 * @brief Classify the document and return the top numResults
			 *
			 * @param document the document to classify
			 * @Param defaultCategory the default category to assign Ties are broken by comparing the category
			 * @Param numResults The maximum number of results to return, ranked by score. Ties are broken by comparing the category
			 * @return A collection of classify result, a vector of ClassifierResult
			 */
			vector<ClassifierResult> classifyDocument(vector<string> &document, string &defaultCategory, int numResults)
			{
				algorithm->classifyDocument(document, datastore, defaultCategory, numResults);
			}

			/**
			 * @brief Gets the lables in the given model
			 *
			 * @return collection of lables in a verctor as string
			 */
			vector<string> getLables()
			{
				return algorithm.getLables(datastore);
			}
	};
}




