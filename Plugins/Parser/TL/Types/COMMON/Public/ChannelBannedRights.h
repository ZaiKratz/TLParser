#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class ChannelBannedRights : public TLBaseObject
{
public:
	ChannelBannedRights();
	ChannelBannedRights(bool view_messages, bool send_messages, bool send_media, bool send_stickers, bool send_gifs, bool send_games, bool send_inline, bool embed_links, FDateTime until_date);

	~ChannelBannedRights();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	bool view_messages;
	 bool send_messages;
	 bool send_media;
	 bool send_stickers;
	 bool send_gifs;
	 bool send_games;
	 bool send_inline;
	 bool embed_links;
	 FDateTime until_date;
};
} //end namespace block
