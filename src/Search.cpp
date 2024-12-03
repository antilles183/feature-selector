#include "Search.h"
#include "Classifier.h"
#include "Validator.h"
#include <queue>
#include <iomanip>



Node Search::forwardSelection(std::set<int> featureSet,
                              double (*eval)(const Node& node))
{
    Node noFeaturesNode;
    Validator v;
    Classifier c;



    noFeaturesNode.setAccuracy( eval(noFeaturesNode) );
    // noFeaturesNode.setAccuracy( v.evaluate({}, ) );

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\tUsing feature(s) " << noFeaturesNode << " accuracy is ";
    std::cout << noFeaturesNode.accuracy() << "%\n\nBeginning search...\n\n";

    Node maxNode = forwardSelectionEngine(featureSet, noFeaturesNode, eval);

    std::cout << "The best feature subset is " << maxNode;
    std::cout << " which has an accuracy of " << maxNode.accuracy() << "%\n";

    return maxNode;

}



Node Search::forwardSelection(const DataSet &dataSet,
                              double (*eval)(const FeatureSet& featureSet, const DataSet& dataSet, Classifier& classifier),
                              Classifier &classifier)
{
    Node noFeaturesNode;

    // noFeaturesNode.setAccuracy( eval(noFeaturesNode) );
    noFeaturesNode.setAccuracy( eval({}, dataSet, classifier) );

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\tUsing feature(s) " << noFeaturesNode << " accuracy is ";
    std::cout << noFeaturesNode.accuracy() << "%\n\nBeginning search...\n\n";

    // build featureSet from dataSet
    FeatureSet featureSet;
    for(int feature = 1; feature < dataSet.at(0).size(); feature++)
        featureSet.insert(feature);

    Node maxNode = forwardSelectionEngine(featureSet, noFeaturesNode, eval, dataSet, classifier);

    std::cout << "The best feature subset is " << maxNode;
    std::cout << " which has an accuracy of " << maxNode.accuracy() << "%\n";

    return maxNode;

}




Node Search::backwardElimination(std::set<int> featureSet,
                                 double (*eval)(const Node& node))
{
    Node allFeaturesNode(featureSet);

    allFeaturesNode.setAccuracy( eval(allFeaturesNode) );

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\tUsing feature(s) " << allFeaturesNode << " accuracy is ";
    std::cout << allFeaturesNode.accuracy() << "%\n\nBeginning search...\n\n";

    Node maxNode = backwardEliminationEngine(featureSet, allFeaturesNode, eval);

    std::cout << "The best feature subset is " << maxNode;
    std::cout << " which has an accuracy of " << maxNode.accuracy() << "%\n";

    return maxNode;

}



Node Search::backwardElimination(const DataSet &dataSet,
                                 double (*eval)(const FeatureSet& featureSet, const DataSet& dataSet, Classifier& classifier),
                                 Classifier &classifier)
{
    // build featureSet from dataSet
    FeatureSet featureSet;
    for(int feature = 1; feature < dataSet.at(0).size(); feature++)
        featureSet.insert(feature);

    Node allFeaturesNode(featureSet);

    // allFeaturesNode.setAccuracy( eval(allFeaturesNode) );
    allFeaturesNode.setAccuracy( eval(allFeaturesNode.fs(), dataSet, classifier) );

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\tUsing feature(s) " << allFeaturesNode << " accuracy is ";
    std::cout << allFeaturesNode.accuracy() << "%\n\nBeginning search...\n\n";

    Node maxNode = backwardEliminationEngine(featureSet, allFeaturesNode, eval, dataSet, classifier);

    std::cout << "The best feature subset is " << maxNode;
    std::cout << " which has an accuracy of " << maxNode.accuracy() << "%\n";

    return maxNode;

}



Node Search::specialAlgorithm(std::set<int> featureSet,
                              double (*eval)(const Node& node))
{

    std::cout << "Not Yet Implemented\n";

    return Node(featureSet);

}



/* # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# PRIVATE HELPERS
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # */



Node Search::forwardSelectionEngine(std::set<int>& featureSet, 
                                    const Node& parent,
                                    double (*eval)(const Node& node))
{
    // BASE CONDITION: no more features
    if(!featureSet.size()){
        std::cout << "Finished search\n\n";
        return Node();
    }

    Node maxChild;
    std::set<int>::iterator it;
    std::set<int>::iterator usefulFeature;

    // traverse features. clone parent adding a different feature to each child
    for(it = featureSet.begin(); it != featureSet.end(); it++ )
    {
        Node child(parent);
        child.insert(*it);
        child.setAccuracy( eval(child) );

        std::cout << "\tUsing feature(s) " << child << " accuracy is ";
        std::cout << child.accuracy() << "%\n";

        if(child > maxChild){
            maxChild = child;
            usefulFeature = it;
        }
    }

    std::cout << "\nFeature set " << maxChild << " was best, accuracy is ";
    std::cout << maxChild.accuracy() << "%\n\n";

    // remove useful feature from featureSet
    featureSet.erase(usefulFeature);

    // RECURSIVE CALL
    maxChild = forwardSelectionEngine(featureSet, maxChild, eval);

    // return max of parent and max child
    return (parent > maxChild) ? parent : maxChild; 

}


Node Search::forwardSelectionEngine(std::set<int>& featureSet, 
                                    const Node& parent,
                                    double (*eval)(const FeatureSet& featureSet, const DataSet& dataSet, Classifier& classifier),
                                    const DataSet &dataSet,
                                    Classifier &classifier)
{
    // BASE CONDITION: no more features
    if(!featureSet.size()){
        std::cout << "Finished search\n\n";
        return Node();
    }

    Node maxChild;
    std::set<int>::iterator it;
    std::set<int>::iterator usefulFeature;

    // traverse features. clone parent adding a different feature to each child
    for(it = featureSet.begin(); it != featureSet.end(); it++ )
    {
        Node child(parent);
        child.insert(*it);
        // child.setAccuracy( eval(child) );
        child.setAccuracy( eval(child.fs(), dataSet, classifier ) );            

        std::cout << "\tUsing feature(s) " << child << " accuracy is ";
        std::cout << child.accuracy() << "%\n";

        if(child > maxChild){
            maxChild = child;
            usefulFeature = it;
        }
    }

    std::cout << "\nFeature set " << maxChild << " was best, accuracy is ";
    std::cout << maxChild.accuracy() << "%\n\n";

    // remove useful feature from featureSet
    featureSet.erase(usefulFeature);

    // RECURSIVE CALL
    // maxChild = forwardSelectionEngine(featureSet, maxChild, eval);
    maxChild = forwardSelectionEngine(featureSet, maxChild, eval, dataSet, classifier);

    // return max of parent and max child
    return (parent > maxChild) ? parent : maxChild; 

}



Node Search::backwardEliminationEngine(std::set<int>& featureSet, 
                                       const Node& parent,
                                       double (*eval)(const Node& node))
{
    // BASE CONDITION: no more features
    if(!featureSet.size()){
        std::cout << "Finished search\n\n";
        return Node();
    }

    Node maxChild;
    std::set<int>::iterator it;
    std::set<int>::iterator usefulFeature;
    std::set<int> featureSubset;

    // traverse features. clone parent adding a different feature to each child
    for(it = featureSet.begin(); it != featureSet.end(); it++ )
    {
        featureSubset = featureSet;
        featureSubset.erase(*it);

        Node child(featureSubset);
        child.setAccuracy( eval(child) );

        std::cout << "\tUsing feature(s) " << child << " accuracy is ";
        std::cout << child.accuracy() << "%\n";

        if(child > maxChild){
            maxChild = child;
            usefulFeature = it;
        }
    }

    std::cout << "\nFeature set " << maxChild << " was best, accuracy is ";
    std::cout << maxChild.accuracy() << "%\n\n";

    // remove useful feature from featureSet
    featureSet.erase(usefulFeature);

    // RECURSIVE CALL
    maxChild = backwardEliminationEngine(featureSet, maxChild, eval);

    // return max of parent and max child
    return (parent > maxChild) ? parent : maxChild; 

}



Node Search::backwardEliminationEngine(std::set<int>& featureSet,
                                       const Node& parent,
                                       double (*eval)(const FeatureSet& featureSet, const DataSet& dataSet, Classifier& classifier),
                                       const DataSet &dataSet,
                                       Classifier &classifier)
{
    // BASE CONDITION: no more features
    if(!featureSet.size()){
        std::cout << "Finished search\n\n";
        return Node();
    }

    Node maxChild;
    std::set<int>::iterator it;
    std::set<int>::iterator usefulFeature;
    std::set<int> featureSubset;

    // traverse features. clone parent adding a different feature to each child
    for(it = featureSet.begin(); it != featureSet.end(); it++ )
    {
        featureSubset = featureSet;
        featureSubset.erase(*it);

        Node child(featureSubset);
        // child.setAccuracy( eval(child) );
        child.setAccuracy( eval(child.fs(), dataSet, classifier) );

        std::cout << "\tUsing feature(s) " << child << " accuracy is ";
        std::cout << child.accuracy() << "%\n";

        if(child > maxChild){
            maxChild = child;
            usefulFeature = it;
        }
    }

    std::cout << "\nFeature set " << maxChild << " was best, accuracy is ";
    std::cout << maxChild.accuracy() << "%\n\n";

    // remove useful feature from featureSet
    featureSet.erase(usefulFeature);

    // RECURSIVE CALL
    maxChild = backwardEliminationEngine(featureSet, maxChild, eval, dataSet, classifier);

    // return max of parent and max child
    return (parent > maxChild) ? parent : maxChild; 

}