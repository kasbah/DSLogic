/*
 * This file is part of the DSLogic-gui project.
 * DSLogic-gui is based on PulseView.
 *
 * Copyright (C) 2012 Joel Holdsworth <joel@airwebreathe.org.uk>
 * Copyright (C) 2013 DreamSourceLab <dreamsourcelab@dreamsourcelab.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
 */


#include "logic.h"
#include "logicsnapshot.h"

using namespace boost;
using namespace std;

namespace pv {
namespace data {

Logic::Logic(unsigned int num_probes, uint64_t samplerate) :
    SignalData(num_probes, samplerate)
{
	assert(_num_probes > 0);
}

void Logic::push_snapshot(
	shared_ptr<LogicSnapshot> &snapshot)
{
	_snapshots.push_front(snapshot);
}

deque< shared_ptr<LogicSnapshot> >& Logic::get_snapshots()
{
	return _snapshots;
}

} // namespace data
} // namespace pv
