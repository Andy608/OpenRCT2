/*****************************************************************************
 * Copyright (c) 2014-2019 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#pragma once

#include "common.h"
#include <memory>
#include <string>
#include <vector>
#include "ride/TrackDesign.h"
#include "core/IStream.hpp"


/**
 * Interface to import scenarios and saved games.
 */
interface ITrackImporter
{
public:
    virtual ~ITrackImporter() = default;

    virtual bool Load(const utf8* path) abstract;
    virtual bool LoadFromStream(
        IStream * stream) abstract;

    virtual std::unique_ptr<TrackDesign> Import() abstract;
};

namespace TrackImporter
{
    std::unique_ptr<ITrackImporter> Create(const std::string& hintPath);
    std::unique_ptr<ITrackImporter> CreateTD4();
    std::unique_ptr<ITrackImporter> CreateTD6();

    bool ExtensionIsRCT1(const std::string& extension);
} // namespace TrackImporter
