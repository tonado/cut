#ifndef PARSERS_Thu_Apr_16_23_57_14_2015_H
#define PARSERS_Thu_Apr_16_23_57_14_2015_H

#include <cpo/core/OptionsDescription.hpp>
#include <cpo/core/Cmdline.hpp>
#include <cpo/core/Option.hpp>
#include <cui/dci/__Role__.h>

CPO_NS_BEGIN

struct OptionsDescription;

CUI_DEF_ROLE(ParsedOptions)
{
    CUI_ABSTRACT(const std::vector<Option>& options() const);
    CUI_ABSTRACT(const OptionsDescription& description() const);
};

struct CommandLineParser : private Cmdline, ParsedOptions{

    CommandLineParser( int argc, const char** argv
                     , const OptionsDescription& desc);

    const ParsedOptions& run();

private:
    CUI_OVERRIDE(const std::vector<Option>& options() const);
    CUI_OVERRIDE(const OptionsDescription& description() const);

private:
    std::vector<Option> parsedOptions;
    const OptionsDescription& desc;
};

CPO_NS_END

#endif
