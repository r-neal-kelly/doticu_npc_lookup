/*
    Copyright � 2020 r-neal-kelly, aka doticu
*/

#pragma once

#include "mcm_bases.h"

namespace doticu_npcl { namespace MCM {

    template <typename Base_t, typename Item_t>
    class References_t : public Bases_t<Base_t, Item_t>
    {
    public:
    };

}}

namespace doticu_npcl { namespace MCM {

    template <typename Base_t, typename Item_t>
    class References_List_t : public Bases_List_t<Base_t, Item_t>
    {
    public:
    };

}}

namespace doticu_npcl { namespace MCM {

    template <typename Base_t, typename Item_t>
    class References_Filter_t : public Bases_Filter_t<Base_t, Item_t>
    {
    public:
        Int_t&  Reference_Search_Option();
        Int_t&  Reference_Select_Option();
        Int_t&  Reference_Negate_Option();

        Int_t&  Worldspace_Search_Option();
        Int_t&  Worldspace_Select_Option();
        Int_t&  Worldspace_Negate_Option();

        Int_t&  Location_Search_Option();
        Int_t&  Location_Select_Option();
        Int_t&  Location_Negate_Option();

        Int_t&  Cell_Search_Option();
        Int_t&  Cell_Select_Option();
        Int_t&  Cell_Negate_Option();

        Int_t&  Interior_Option();
        Int_t&  Exterior_Option();

    public:
        V::String_Variable_t*   Reference_Argument_Variable();
        V::Bool_Variable_t*     Reference_Do_Negate_Variable();

        V::String_Variable_t*   Worldspace_Argument_Variable();
        V::Bool_Variable_t*     Worldspace_Do_Negate_Variable();

        V::String_Variable_t*   Location_Argument_Variable();
        V::Bool_Variable_t*     Location_Do_Negate_Variable();

        V::String_Variable_t*   Cell_Argument_Variable();
        V::Bool_Variable_t*     Cell_Do_Negate_Variable();

        V::Int_Variable_t*      Interior_Exterior_Argument_Variable();

    public:
        String_t    Reference_Argument();
        void        Reference_Argument(String_t value);
        Bool_t      Reference_Do_Negate();
        void        Reference_Do_Negate(Bool_t value);

        String_t    Worldspace_Argument();
        void        Worldspace_Argument(String_t value);
        Bool_t      Worldspace_Do_Negate();
        void        Worldspace_Do_Negate(Bool_t value);

        String_t    Location_Argument();
        void        Location_Argument(String_t value);
        Bool_t      Location_Do_Negate();
        void        Location_Do_Negate(Bool_t value);

        String_t    Cell_Argument();
        void        Cell_Argument(String_t value);
        Bool_t      Cell_Do_Negate();
        void        Cell_Do_Negate(Bool_t value);

        Binary_e    Interior_Exterior_Argument();
        void        Interior_Exterior_Argument(Binary_e value);

    public:
        void                    Clear();
        Filter_State_t<Item_t>  Execute(Vector_t<Item_t>* read, Vector_t<Item_t>* write);

        Vector_t<String_t>      Selectable_References();
        Vector_t<String_t>      Selectable_Worldspaces();
        Vector_t<String_t>      Selectable_Locations();
        Vector_t<String_t>      Selectable_Cells();
    };

}}

namespace doticu_npcl { namespace MCM {

    template <typename Base_t, typename Item_t>
    class References_Options_t : public Bases_Options_t<Base_t, Item_t>
    {
    public:
    };

}}

namespace doticu_npcl { namespace MCM {

    template <typename Base_t, typename Item_t>
    class References_Item_t : public Bases_Item_t<Base_t, Item_t>
    {
    public:
        Int_t& Select_In_Console_Option();
        Int_t& Mark_On_Map_Option();
    };

}}
