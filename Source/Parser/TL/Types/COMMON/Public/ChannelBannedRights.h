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

	bool GetViewMessages() const
	{
		 return this->view_messages;
	}

	bool GetSendMessages() const
	{
		 return this->send_messages;
	}

	bool GetSendMedia() const
	{
		 return this->send_media;
	}

	bool GetSendStickers() const
	{
		 return this->send_stickers;
	}

	bool GetSendGifs() const
	{
		 return this->send_gifs;
	}

	bool GetSendGames() const
	{
		 return this->send_games;
	}

	bool GetSendInline() const
	{
		 return this->send_inline;
	}

	bool GetEmbedLinks() const
	{
		 return this->embed_links;
	}

	FDateTime GetUntilDate() const
	{
		 return this->until_date;
	}

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
