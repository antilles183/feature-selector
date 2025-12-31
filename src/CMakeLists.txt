add_library(featureSelectorLib
    InputOutput.cpp
    Node.cpp
    Evaluator.cpp
    Search.cpp
    Classifier.cpp
    Validator.cpp
    Stopwatch.cpp
)

target_link_libraries(featureSelectorLib)