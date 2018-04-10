#pragma once

struct DispatcherErrorMessagesStore
{
	static constexpr const char* disconectFailedNoListenersForThisEvent = "Failed to disconnect. The dispatcher has no listeners for this event.";

	static constexpr const char* disconectFailedWrongToken = "Failed to disconnect. Wrong token. The dispatcher has no listeners with this token.";
};