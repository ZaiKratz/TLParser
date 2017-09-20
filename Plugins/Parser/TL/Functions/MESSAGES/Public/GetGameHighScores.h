#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/InputPeer.h"
#include "../../../Types/Common/Public/InputUser.h"
#include "../../../Types/Messages/Public/HighScores.h"

//begin namespace block
namespace MESSAGES
{
class GetGameHighScores : public TLBaseObject
{
public:
	GetGameHighScores();
	GetGameHighScores(PRIVATE::InputPeer* peer, int32 id, COMMON::InputUser* user_id);

	~GetGameHighScores();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	PRIVATE::InputPeer* peer;
	 int32 id;
	 COMMON::InputUser* user_id;
	MESSAGES::HighScores* result;
};
} //end namespace block
