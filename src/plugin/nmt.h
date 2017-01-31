#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <memory>

#include "common/god.h"
#include "common/scorer.h"
#include "common/sentence.h"
#include "gpu/mblas/matrix.h"
#include "gpu/decoder/encoder_decoder.h"
#include "neural_phrase.h"
#include "hypo_info.h"

namespace amunmt {

class Vocab;

class StateInfo;
class NeuralPhrase;
typedef std::shared_ptr<StateInfo> StateInfoPtr;

typedef std::vector<size_t> Batch;
typedef std::vector<Batch> Batches;
typedef std::vector<StateInfoPtr> StateInfos;
typedef std::vector<float> Scores;
typedef std::vector<size_t> LastWords;

class MosesPlugin {
  public:
    MosesPlugin();
		~MosesPlugin();
		
    static size_t GetDevices(size_t = 1);
    void SetDevice();
    size_t GetDevice();
    const amunmt::God &GetGod() const
    { return god_; }

    void initGod(const std::string& configPath);

    States SetSource(const std::vector<size_t>& words);


  private:
    amunmt::God god_;
    
};

}