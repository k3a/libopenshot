/**
 * @file
 * @brief Source file for VideoPlaybackThread class
 * @author Duzy Chan <code@duzy.info>
 * @author Jonathan Thomas <jonathan@openshot.org>
 *
 * @section LICENSE
 *
 * Copyright (c) 2008-2014 OpenShot Studios, LLC
 * <http://www.openshotstudios.com/>. This file is part of
 * OpenShot Library (libopenshot), an open-source project dedicated to
 * delivering high quality video editing and animation solutions to the
 * world. For more information visit <http://www.openshot.org/>.
 *
 * OpenShot Library (libopenshot) is free software: you can redistribute it
 * and/or modify it under the terms of the GNU Affero General Public License
 * as published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * OpenShot Library (libopenshot) is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with OpenShot Library. If not, see <http://www.gnu.org/licenses/>.
 *
 * Also, if your software can interact with users remotely through a computer
 * network, you should also make sure that it provides a way for users to
 * get its source. For example, if your program is a web application, its
 * interface could display a "Source" link that leads users to an archive
 * of the code. There are many ways you could offer source, and different
 * solutions will be better for different programs; see section 13 for the
 * specific requirements.
 *
 * You should also get your employer (if you work as a programmer) or school,
 * if any, to sign a "copyright disclaimer" for the program, if necessary.
 * For more information on this, and how to apply and follow the GNU AGPL, see
 * <http://www.gnu.org/licenses/>.
 */

#ifndef OPENSHOT_VIDEO_PLAYBACK_THREAD_H
#define OPENSHOT_VIDEO_PLAYBACK_THREAD_H

#include "../../include/ReaderBase.h"
#include "../../include/RendererBase.h"

namespace openshot
{
    using juce::Thread;
    using juce::WaitableEvent;

    /**
     *  @brief The video playback class.
     */
    class VideoPlaybackThread : Thread
    {
	RendererBase *renderer;
	std::tr1::shared_ptr<Frame> frame;
	WaitableEvent render;
	WaitableEvent rendered;
	bool reset;

	/// Constructor
	VideoPlaybackThread(RendererBase *rb);
	/// Destructor
	~VideoPlaybackThread();

	/// Get the currently playing frame number (if any)
	int getCurrentFramePosition();

	/// Start the thread
	void run();

	/// Parent class of VideoPlaybackThread
	friend class PlayerPrivate;
	friend class QtPlayer;
    };

}

#endif // OPENSHOT_VIDEO_PLAYBACK_THREAD_H