#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class InputBotInlineMessageID : public TLBaseObject
{
public:
	InputBotInlineMessageID();
	InputBotInlineMessageID(int32 dc_id, unsigned long long id, unsigned long long access_hash);

	~InputBotInlineMessageID();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 dc_id;
	 unsigned long long id;
	 unsigned long long access_hash;
};
} //end namespace block
