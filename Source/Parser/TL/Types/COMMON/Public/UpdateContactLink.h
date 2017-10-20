#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class UpdateContactLink : public TLBaseObject
{
public:
	UpdateContactLink();
	UpdateContactLink(int32 user_id, TLBaseObject* my_link, TLBaseObject* foreign_link);

	~UpdateContactLink();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 GetUserId() const
	{
		 return this->user_id;
	}

	TLBaseObject*  GetMyLink() const
	{
		 return this->my_link;
	}

	TLBaseObject*  GetForeignLink() const
	{
		 return this->foreign_link;
	}

private:
	int32 user_id;
	 TLBaseObject* my_link;
	 TLBaseObject* foreign_link;
};
} //end namespace block
