#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

// Structure to represent a pipeline stage
struct PipelineStage {
    string name;
    bool isSuccessful;
    string errorMessage;
};

// Structure to represent a DevOps pipeline
struct DevOpsPipeline {
    string name;
    vector<PipelineStage> stages;
};

// Function to add a stage to the pipeline
void addStageToPipeline(DevOpsPipeline& pipeline, const string& stageName) {
    PipelineStage stage;
    stage.name = stageName;
    stage.isSuccessful = false;
    pipeline.stages.push_back(stage);
}

// Function to update the status of a pipeline stage
void updateStageStatus(DevOpsPipeline& pipeline, const string& stageName, bool status, const string& errorMessage = "") {
    for (auto& stage : pipeline.stages) {
        if (stage.name == stageName) {
            stage.isSuccessful = status;
            stage.errorMessage = errorMessage;
            break;
        }
    }
}

// Function to print the pipeline status
void printPipelineStatus(const DevOpsPipeline& pipeline) {
    cout << "Pipeline: " << pipeline.name << endl;
    for (const auto& stage : pipeline.stages) {
        cout << "  " << stage.name << ": " << (stage.isSuccessful ? "SUCCESS" : "FAILED") << endl;
        if (!stage.isSuccessful) {
            cout << "    Error Message: " << stage.errorMessage << endl;
        }
    }
}

int main() {
    DevOpsPipeline pipeline;
    pipeline.name = "Automated DevOps Pipeline";

    addStageToPipeline(pipeline, "Build");
    addStageToPipeline(pipeline, "Test");
    addStageToPipeline(pipeline, "Deploy");

    updateStageStatus(pipeline, "Build", true);
    updateStageStatus(pipeline, "Test", true);
    updateStageStatus(pipeline, "Deploy", false, "Deployment failed due to network issues");

    printPipelineStatus(pipeline);

    return 0;
}