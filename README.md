# feature-selector

An implementation of Forward Selection and Backward Elimination feature selection algorithms — built from scratch in C++ for an Intro to AI course. Parses and normalizes Titanic data sets before performing chosen algorithm with verbose output. Uses Nearest Neighbor classification and a simple k-fold cross validation of leave one out.

<br/>

## Compile & Run
```bash
cd feature-selector
cmake -B build
cd build
make
./bin/feature-selector
```
<br/>

## About the Data

| Dataset                 | # of Features | # of Datapoints |
| ----------------------- | ------------- | --------------- |
| small-test-dataset      | 11            | 100             |
| large-test-dataset      | 41            | 1000            |
| titanic-clean           | 7             | 714             |