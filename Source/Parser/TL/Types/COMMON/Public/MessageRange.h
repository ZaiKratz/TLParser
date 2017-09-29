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

	int32 GetMinId() const
	{
		 return this->min_id;
	}

	int32 GetMaxId() const
	{
		 return this->max_id;
	}

private:
	int32 min_id;
	 int32 max_id;
};
} //end namespace block
