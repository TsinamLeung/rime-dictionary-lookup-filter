//
//  MultiReverseLookupFilter.hpp
//  rime-multi-reverse-lookup-filter-objs
//
//  Created by leung tsinam on 28/10/2022.
//

#ifndef MultiReverseLookupFilter_hpp
#define MultiReverseLookupFilter_hpp

#include <rime/common.h>
#include <rime/filter.h>
#include <rime/algo/algebra.h>
#include <rime/gear/filter_commons.h>
#include <rime/ticket.h>
#include <rime/dict/dictionary.h>


namespace rime {

class Dictionary;

class DictionaryLookupFilter : public Filter, TagMatching {
public:
    explicit DictionaryLookupFilter(const Ticket& ticket);

    virtual an<Translation> Apply(an<Translation> translation,
                                  CandidateList* candidates);

    virtual bool AppliesToSegment(Segment* segment) {
        return TagsMatch(segment);
    }

    void Process(const an<Candidate>& cand);
    
protected:
    void Initialize();
    
    bool initialized_ = false;
    the<Dictionary> dict_;
    // settings
    Projection comment_formatter_;
    string dictname_;

};
};

#endif /* MultiReverseLookupFilter_hpp */
