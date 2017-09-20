#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class MessageRange : public TLBaseObject
{
public:
	MessageRange();
	MessageRange(int32 min_id, int32 max_id);

	~MessageRange();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 min_id;
	 int32 max_id;
};
} //end namespace block
