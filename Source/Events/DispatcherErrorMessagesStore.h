#pragma once

struct DispatcherErrorMessagesStore
{
	static constexpr const char* disconectFailedNoListenersToDisconect = "Failed to disconnect. The dispatcher has no listeners.";

	static constexpr const char* disconectFailedWrongToken = "Failed to disconnect. Wrong token. The dispatcher has no listeners with this token.";
};