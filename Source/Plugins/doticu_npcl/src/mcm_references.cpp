/*
    Copyright � 2020 r-neal-kelly, aka doticu
*/

#include "doticu_skylib/virtual_macros.h"

#include "consts.h"
#include "mcm_references.h"

namespace doticu_npcl { namespace MCM {

    /* References_t */

    References_t*       References_t::Self()                    { return static_cast<References_t*>(Consts_t::NPCL_MCM_Quest()); }
    String_t            References_t::Class_Name()              { DEFINE_CLASS_NAME("doticu_npcl_mcm_references"); }
    Class_t*            References_t::Class()                   { DEFINE_CLASS(); }
    Object_t*           References_t::Object()                  { DEFINE_OBJECT(); }

    String_Variable_t*  References_t::Current_View_Variable()   { DEFINE_STRING_VARIABLE("p_current_view"); }
    Int_Variable_t*     References_t::Options_Offset_Variable() { DEFINE_INT_VARIABLE("p_options_offset"); }

    References_t::View_e References_t::Current_View()
    {
        String_t current_view = Current_View_Variable()->Value();
        if (CString_t::Is_Same(current_view, LIST_VIEW, true)) {
            return View_e::LIST;
        } else if (CString_t::Is_Same(current_view, FILTER_VIEW, true)) {
            return View_e::FILTER;
        } else if (CString_t::Is_Same(current_view, OPTIONS_VIEW, true)) {
            return View_e::OPTIONS;
        } else if (CString_t::Is_Same(current_view, ITEM_VIEW, true)) {
            return View_e::ITEM;
        } else {
            Current_View_Variable()->Value(LIST_VIEW);
            return View_e::LIST;
        }
    }

    void References_t::Current_View(References_t::View_e value)
    {
        if (value == View_e::LIST) {
            Current_View_Variable()->Value(LIST_VIEW);
        } else if (value == View_e::FILTER) {
            Current_View_Variable()->Value(FILTER_VIEW);
        } else if (value == View_e::OPTIONS) {
            Current_View_Variable()->Value(OPTIONS_VIEW);
        } else if (value == View_e::ITEM) {
            Current_View_Variable()->Value(ITEM_VIEW);
        } else {
            Current_View_Variable()->Value(LIST_VIEW);
        }
    }

    Int_t References_t::Options_Offset()
    {
        return Options_Offset_Variable()->Value();
    }

    void References_t::Options_Offset(Int_t value)
    {
        Options_Offset_Variable()->Value(value);
    }

    References_List_t* References_t::List()
    {
        return static_cast<References_List_t*>(this);
    }

    References_Filter_t* References_t::Filter()
    {
        return static_cast<References_Filter_t*>(this);
    }

    References_Options_t* References_t::Options()
    {
        return static_cast<References_Options_t*>(this);
    }

    References_Item_t* References_t::Item()
    {
        return static_cast<References_Item_t*>(this);
    }

    void References_t::On_Build_Page(Latent_Callback_i* lcallback)
    {
        View_e current_view = Current_View();
             if (current_view == View_e::LIST)      List()->On_Build_Page(lcallback);
        else if (current_view == View_e::FILTER)    Filter()->On_Build_Page(lcallback);
        else if (current_view == View_e::OPTIONS)   Options()->On_Build_Page(lcallback);
        else if (current_view == View_e::ITEM)      Item()->On_Build_Page(lcallback);
        else                                        SKYLIB_ASSERT(false);
    }

    void References_t::On_Option_Select(Int_t option, Latent_Callback_i* lcallback)
    {
        View_e current_view = Current_View();
             if (current_view == View_e::LIST)      List()->On_Option_Select(option, lcallback);
        else if (current_view == View_e::FILTER)    Filter()->On_Option_Select(option, lcallback);
        else if (current_view == View_e::OPTIONS)   Options()->On_Option_Select(option, lcallback);
        else if (current_view == View_e::ITEM)      Item()->On_Option_Select(option, lcallback);
        else                                        SKYLIB_ASSERT(false);
    }

    void References_t::On_Option_Menu_Open(Int_t option, Latent_Callback_i* lcallback)
    {
        View_e current_view = Current_View();
             if (current_view == View_e::LIST)      List()->On_Option_Menu_Open(option, lcallback);
        else if (current_view == View_e::FILTER)    Filter()->On_Option_Menu_Open(option, lcallback);
        else if (current_view == View_e::OPTIONS)   Options()->On_Option_Menu_Open(option, lcallback);
        else if (current_view == View_e::ITEM)      Item()->On_Option_Menu_Open(option, lcallback);
        else                                        SKYLIB_ASSERT(false);
    }

    void References_t::On_Option_Menu_Accept(Int_t option, Int_t idx, Latent_Callback_i* lcallback)
    {
        View_e current_view = Current_View();
             if (current_view == View_e::LIST)      List()->On_Option_Menu_Accept(option, idx, lcallback);
        else if (current_view == View_e::FILTER)    Filter()->On_Option_Menu_Accept(option, idx, lcallback);
        else if (current_view == View_e::OPTIONS)   Options()->On_Option_Menu_Accept(option, idx, lcallback);
        else if (current_view == View_e::ITEM)      Item()->On_Option_Menu_Accept(option, idx, lcallback);
        else                                        SKYLIB_ASSERT(false);
    }

    void References_t::On_Option_Slider_Open(Int_t option, Latent_Callback_i* lcallback)
    {
        View_e current_view = Current_View();
             if (current_view == View_e::LIST)      List()->On_Option_Slider_Open(option, lcallback);
        else if (current_view == View_e::FILTER)    Filter()->On_Option_Slider_Open(option, lcallback);
        else if (current_view == View_e::OPTIONS)   Options()->On_Option_Slider_Open(option, lcallback);
        else if (current_view == View_e::ITEM)      Item()->On_Option_Slider_Open(option, lcallback);
        else                                        SKYLIB_ASSERT(false);
    }

    void References_t::On_Option_Slider_Accept(Int_t option, Float_t value, Latent_Callback_i* lcallback)
    {
        View_e current_view = Current_View();
             if (current_view == View_e::LIST)      List()->On_Option_Slider_Accept(option, value, lcallback);
        else if (current_view == View_e::FILTER)    Filter()->On_Option_Slider_Accept(option, value, lcallback);
        else if (current_view == View_e::OPTIONS)   Options()->On_Option_Slider_Accept(option, value, lcallback);
        else if (current_view == View_e::ITEM)      Item()->On_Option_Slider_Accept(option, value, lcallback);
        else                                        SKYLIB_ASSERT(false);
    }

    void References_t::On_Option_Input_Accept(Int_t option, String_t value, Latent_Callback_i* lcallback)
    {
        View_e current_view = Current_View();
             if (current_view == View_e::LIST)      List()->On_Option_Input_Accept(option, value, lcallback);
        else if (current_view == View_e::FILTER)    Filter()->On_Option_Input_Accept(option, value, lcallback);
        else if (current_view == View_e::OPTIONS)   Options()->On_Option_Input_Accept(option, value, lcallback);
        else if (current_view == View_e::ITEM)      Item()->On_Option_Input_Accept(option, value, lcallback);
        else                                        SKYLIB_ASSERT(false);
    }

    void References_t::On_Option_Keymap_Change(Int_t option, Int_t key, String_t conflict, String_t mod, Latent_Callback_i* lcallback)
    {
        View_e current_view = Current_View();
             if (current_view == View_e::LIST)      List()->On_Option_Keymap_Change(option, key, conflict, mod, lcallback);
        else if (current_view == View_e::FILTER)    Filter()->On_Option_Keymap_Change(option, key, conflict, mod, lcallback);
        else if (current_view == View_e::OPTIONS)   Options()->On_Option_Keymap_Change(option, key, conflict, mod, lcallback);
        else if (current_view == View_e::ITEM)      Item()->On_Option_Keymap_Change(option, key, conflict, mod, lcallback);
        else                                        SKYLIB_ASSERT(false);
    }

    void References_t::On_Option_Default(Int_t option, Latent_Callback_i* lcallback)
    {
        View_e current_view = Current_View();
             if (current_view == View_e::LIST)      List()->On_Option_Default(option, lcallback);
        else if (current_view == View_e::FILTER)    Filter()->On_Option_Default(option, lcallback);
        else if (current_view == View_e::OPTIONS)   Options()->On_Option_Default(option, lcallback);
        else if (current_view == View_e::ITEM)      Item()->On_Option_Default(option, lcallback);
        else                                        SKYLIB_ASSERT(false);
    }

    void References_t::On_Option_Highlight(Int_t option, Latent_Callback_i* lcallback)
    {
        View_e current_view = Current_View();
             if (current_view == View_e::LIST)      List()->On_Option_Highlight(option, lcallback);
        else if (current_view == View_e::FILTER)    Filter()->On_Option_Highlight(option, lcallback);
        else if (current_view == View_e::OPTIONS)   Options()->On_Option_Highlight(option, lcallback);
        else if (current_view == View_e::ITEM)      Item()->On_Option_Highlight(option, lcallback);
        else                                        SKYLIB_ASSERT(false);
    }

    void References_t::Register_Me(Machine_t* machine)
    {
    }

    /* References_List_t */

    Int_Variable_t* References_List_t::Filter_Option_Variable()         { DEFINE_INT_VARIABLE("p_list_filter_option"); }
    Int_Variable_t* References_List_t::Options_Option_Variable()        { DEFINE_INT_VARIABLE("p_list_options_option"); }
    Int_Variable_t* References_List_t::Previous_Page_Option_Variable()  { DEFINE_INT_VARIABLE("p_list_previous_page_option"); }
    Int_Variable_t* References_List_t::Next_Page_Option_Variable()      { DEFINE_INT_VARIABLE("p_list_next_page_option"); }
    Int_Variable_t* References_List_t::Page_Index_Variable()            { DEFINE_INT_VARIABLE("p_list_page_index"); }

    Int_t References_List_t::Page_Index()
    {
        return Page_Index_Variable()->Value();
    }

    void References_List_t::Page_Index(Int_t value)
    {
        Page_Index_Variable()->Value(value);
    }

    String_t References_List_t::Format_Title(Int_t item_count, Int_t page_index, Int_t page_count)
    {
        std::string items =
            std::string("References: ") +
            std::to_string(item_count);

        std::string pages =
            std::string("Page: ") +
            std::to_string(page_index + 1) + "/" +
            std::to_string(page_count);

        return (items + "               " + pages).c_str();
    }

    Vector_t<Loaded_Actor_t>& References_List_t::Loaded_Actors()
    {
        static Vector_t<Loaded_Actor_t> read;
        read.reserve(2048);
        read.resize(0);
        Actor_t::Loaded_Actors(read);

        static Vector_t<Loaded_Actor_t> write;
        write.reserve(2048);
        write.resize(0);

        Vector_t<Loaded_Actor_t>& results = Filter()->Execute(&read, &write);

        results.Sort(
            [](Loaded_Actor_t* item_a, Loaded_Actor_t* item_b)->Int_t
            {
                const char* name_a = item_a ? item_a->actor->Any_Name() : "";
                const char* name_b = item_b ? item_b->actor->Any_Name() : "";
                return Main_t::String_Comparator(name_a, name_b);
            }
        );

        return results;
    }

    Loaded_Actor_t References_List_t::Option_To_Loaded_Actor(Int_t option)
    {
        Int_t relative_idx = option - Options_Offset() - HEADERS_PER_PAGE;
        if (relative_idx > -1 && relative_idx < ITEMS_PER_PAGE) {
            Vector_t<Loaded_Actor_t>& loaded_actors = Loaded_Actors();
            Int_t absolute_idx = Page_Index() * ITEMS_PER_PAGE + relative_idx;
            if (absolute_idx > -1 && absolute_idx < loaded_actors.size()) {
                return loaded_actors[absolute_idx];
            } else {
                return Loaded_Actor_t();
            }
        } else {
            return Loaded_Actor_t();
        }
    }

    void References_List_t::On_Build_Page(Latent_Callback_i* lcallback)
    {
        Main_t* mcm = Main_t::Self();

        mcm->Cursor_Position(0);
        mcm->Cursor_Fill_Mode(Cursor_e::LEFT_TO_RIGHT);

        Vector_t<Loaded_Actor_t>& loaded_actors = Loaded_Actors();
        size_t loaded_actor_count = loaded_actors.size();
        if (loaded_actor_count) {
            Int_t page_count = static_cast<Int_t>(ceilf(
                static_cast<Float_t>(loaded_actor_count) / static_cast<Float_t>(ITEMS_PER_PAGE)
            ));

            Int_t page_index = Page_Index();
            if (page_index < 0) {
                page_index = 0;
                Page_Index(page_index);
            } else if (page_index >= page_count) {
                page_index = page_count - 1;
                Page_Index(page_index);
            }

            mcm->Title_Text(Format_Title(loaded_actor_count, page_index, page_count));

            Filter_Option_Variable()->Value(mcm->Add_Text_Option(Main_t::FILTER_LABEL, ""));
            Options_Option_Variable()->Value(mcm->Add_Text_Option(Main_t::OPTIONS_LABEL, ""));
            if (page_count > 1) {
                Previous_Page_Option_Variable()->Value(mcm->Add_Text_Option(Main_t::PREVIOUS_PAGE_LABEL, ""));
                Next_Page_Option_Variable()->Value(mcm->Add_Text_Option(Main_t::NEXT_PAGE_LABEL, ""));
            } else {
                Previous_Page_Option_Variable()->Value(mcm->Add_Text_Option(Main_t::PREVIOUS_PAGE_LABEL, "", Flag_e::DISABLE));
                Next_Page_Option_Variable()->Value(mcm->Add_Text_Option(Main_t::NEXT_PAGE_LABEL, "", Flag_e::DISABLE));
            }

            mcm->Add_Header_Option("");
            mcm->Add_Header_Option("");

            Int_t begin = ITEMS_PER_PAGE * page_index;
            Int_t end = begin + ITEMS_PER_PAGE;
            if (end > loaded_actor_count) {
                end = loaded_actor_count;
            }
            for (; begin < end; begin += 1) {
                Loaded_Actor_t loaded_actor = loaded_actors[begin];
                mcm->Add_Text_Option(loaded_actor.actor->Any_Name(), "...");
            }

            Options_Offset(Filter_Option_Variable()->Value());
        } else {
            mcm->Title_Text(Format_Title(0, 0, 1));

            Filter_Option_Variable()->Value(mcm->Add_Text_Option(Main_t::FILTER_LABEL, ""));
            Options_Option_Variable()->Value(mcm->Add_Text_Option(Main_t::OPTIONS_LABEL, ""));
            Previous_Page_Option_Variable()->Value(mcm->Add_Text_Option(Main_t::PREVIOUS_PAGE_LABEL, "", Flag_e::DISABLE));
            Next_Page_Option_Variable()->Value(mcm->Add_Text_Option(Main_t::NEXT_PAGE_LABEL, "", Flag_e::DISABLE));

            mcm->Add_Header_Option(" No Loaded Actors ");

            Options_Offset(Filter_Option_Variable()->Value());
        }

        mcm->Destroy_Latent_Callback(lcallback);
    }

    void References_List_t::On_Option_Select(Int_t option, Latent_Callback_i* lcallback)
    {
        Main_t* mcm = Main_t::Self();

        if (option == Filter_Option_Variable()->Value()) {
            mcm->Disable_Option(option);
            Current_View(View_e::FILTER);
            mcm->Reset_Page();
        } else if (option == Options_Option_Variable()->Value()) {
            mcm->Disable_Option(option);
            Current_View(View_e::OPTIONS);
            mcm->Reset_Page();
        } else if (option == Previous_Page_Option_Variable()->Value()) {
            mcm->Disable_Option(option);

            Vector_t<Loaded_Actor_t>& loaded_actors = Loaded_Actors();
            size_t actor_base_count = loaded_actors.size();
            if (actor_base_count > 0) {
                Int_t page_count = static_cast<Int_t>(ceilf(
                    static_cast<Float_t>(actor_base_count) / static_cast<Float_t>(ITEMS_PER_PAGE)
                ));

                Int_t page_index = Page_Index();
                if (page_index == 0) {
                    page_index = page_count - 1;
                } else {
                    page_index -= 1;
                }
                Page_Index(page_index);
            }

            mcm->Reset_Page();
        } else if (option == Next_Page_Option_Variable()->Value()) {
            mcm->Disable_Option(option);

            Vector_t<Loaded_Actor_t>& loaded_actors = Loaded_Actors();
            size_t actor_base_count = loaded_actors.size();
            if (actor_base_count > 0) {
                Int_t page_count = static_cast<Int_t>(ceilf(
                    static_cast<Float_t>(actor_base_count) / static_cast<Float_t>(ITEMS_PER_PAGE)
                ));

                Int_t page_index = Page_Index();
                if (page_index == page_count - 1) {
                    page_index = 0;
                } else {
                    page_index += 1;
                }
                Page_Index(page_index);
            }

            mcm->Reset_Page();
        } else {
            Loaded_Actor_t loaded_actor = Option_To_Loaded_Actor(option);
            if (loaded_actor.actor && loaded_actor.cell) {
                //mcm->Disable_Option(option);

                mcm->Flicker_Option(option);
                mcm->Show_Message((std::string("Would open item menu for ") + loaded_actor.actor->Any_Name().data + ".").c_str());

                //mcm->Reset_Page();
            }
        }

        mcm->Destroy_Latent_Callback(lcallback);
    }

    void References_List_t::On_Option_Menu_Open(Int_t option, Latent_Callback_i* lcallback)
    {
        Main_t::Self()->Destroy_Latent_Callback(lcallback);
    }

    void References_List_t::On_Option_Menu_Accept(Int_t option, Int_t idx, Latent_Callback_i* lcallback)
    {
        Main_t::Self()->Destroy_Latent_Callback(lcallback);
    }

    void References_List_t::On_Option_Slider_Open(Int_t option, Latent_Callback_i* lcallback)
    {
        Main_t::Self()->Destroy_Latent_Callback(lcallback);
    }

    void References_List_t::On_Option_Slider_Accept(Int_t option, Float_t value, Latent_Callback_i* lcallback)
    {
        Main_t::Self()->Destroy_Latent_Callback(lcallback);
    }

    void References_List_t::On_Option_Input_Accept(Int_t option, String_t value, Latent_Callback_i* lcallback)
    {
        Main_t::Self()->Destroy_Latent_Callback(lcallback);
    }

    void References_List_t::On_Option_Keymap_Change(Int_t option, Int_t key, String_t conflict, String_t mod, Latent_Callback_i* lcallback)
    {
        Main_t::Self()->Destroy_Latent_Callback(lcallback);
    }

    void References_List_t::On_Option_Default(Int_t option, Latent_Callback_i* lcallback)
    {
        Main_t::Self()->Destroy_Latent_Callback(lcallback);
    }

    void References_List_t::On_Option_Highlight(Int_t option, Latent_Callback_i* lcallback)
    {
        Main_t::Self()->Destroy_Latent_Callback(lcallback);
    }

    /* References_Filter_t */

    Int_Variable_t*     References_Filter_t::Back_Option_Variable()                 { DEFINE_INT_VARIABLE("p_filter_back_option"); }
    Int_Variable_t*     References_Filter_t::Clear_Option_Variable()                { DEFINE_INT_VARIABLE("p_filter_clear_option"); }

    Int_Variable_t*     References_Filter_t::Mod_Search_Option_Variable()           { DEFINE_INT_VARIABLE("p_filter_mod_search_option"); }
    Int_Variable_t*     References_Filter_t::Mod_Select_Option_Variable()           { DEFINE_INT_VARIABLE("p_filter_mod_select_option"); }
    Int_Variable_t*     References_Filter_t::Mod_Negate_Option_Variable()           { DEFINE_INT_VARIABLE("p_filter_mod_negate_option"); }
    String_Variable_t*  References_Filter_t::Mod_Argument_Variable()                { DEFINE_STRING_VARIABLE("p_filter_mod_argument"); }
    Bool_Variable_t*    References_Filter_t::Mod_Do_Negate_Variable()               { DEFINE_BOOL_VARIABLE("p_filter_mod_do_negate"); }

    Int_Variable_t*     References_Filter_t::Race_Search_Option_Variable()          { DEFINE_INT_VARIABLE("p_filter_race_search_option"); }
    Int_Variable_t*     References_Filter_t::Race_Select_Option_Variable()          { DEFINE_INT_VARIABLE("p_filter_race_select_option"); }
    Int_Variable_t*     References_Filter_t::Race_Negate_Option_Variable()          { DEFINE_INT_VARIABLE("p_filter_race_negate_option"); }
    String_Variable_t*  References_Filter_t::Race_Argument_Variable()               { DEFINE_STRING_VARIABLE("p_filter_race_argument"); }
    Bool_Variable_t*    References_Filter_t::Race_Do_Negate_Variable()              { DEFINE_BOOL_VARIABLE("p_filter_race_do_negate"); }

    Int_Variable_t*     References_Filter_t::Base_Search_Option_Variable()          { DEFINE_INT_VARIABLE("p_filter_base_search_option"); }
    Int_Variable_t*     References_Filter_t::Base_Select_Option_Variable()          { DEFINE_INT_VARIABLE("p_filter_base_select_option"); }
    Int_Variable_t*     References_Filter_t::Base_Negate_Option_Variable()          { DEFINE_INT_VARIABLE("p_filter_base_negate_option"); }
    String_Variable_t*  References_Filter_t::Base_Argument_Variable()               { DEFINE_STRING_VARIABLE("p_filter_base_argument"); }
    Bool_Variable_t*    References_Filter_t::Base_Do_Negate_Variable()              { DEFINE_BOOL_VARIABLE("p_filter_base_do_negate"); }

    Int_Variable_t*     References_Filter_t::Name_Search_Option_Variable()          { DEFINE_INT_VARIABLE("p_filter_name_search_option"); }
    Int_Variable_t*     References_Filter_t::Name_Select_Option_Variable()          { DEFINE_INT_VARIABLE("p_filter_name_select_option"); }
    Int_Variable_t*     References_Filter_t::Name_Negate_Option_Variable()          { DEFINE_INT_VARIABLE("p_filter_name_negate_option"); }
    String_Variable_t*  References_Filter_t::Name_Argument_Variable()               { DEFINE_STRING_VARIABLE("p_filter_name_argument"); }
    Bool_Variable_t*    References_Filter_t::Name_Do_Negate_Variable()              { DEFINE_BOOL_VARIABLE("p_filter_name_do_negate"); }

    Int_Variable_t*     References_Filter_t::Location_Search_Option_Variable()      { DEFINE_INT_VARIABLE("p_filter_location_search_option"); }
    Int_Variable_t*     References_Filter_t::Location_Select_Option_Variable()      { DEFINE_INT_VARIABLE("p_filter_location_select_option"); }
    Int_Variable_t*     References_Filter_t::Location_Negate_Option_Variable()      { DEFINE_INT_VARIABLE("p_filter_location_negate_option"); }
    String_Variable_t*  References_Filter_t::Location_Argument_Variable()           { DEFINE_STRING_VARIABLE("p_filter_location_argument"); }
    Bool_Variable_t*    References_Filter_t::Location_Do_Negate_Variable()          { DEFINE_BOOL_VARIABLE("p_filter_location_do_negate"); }

    Int_Variable_t*     References_Filter_t::Cell_Search_Option_Variable()          { DEFINE_INT_VARIABLE("p_filter_cell_search_option"); }
    Int_Variable_t*     References_Filter_t::Cell_Select_Option_Variable()          { DEFINE_INT_VARIABLE("p_filter_cell_select_option"); }
    Int_Variable_t*     References_Filter_t::Cell_Negate_Option_Variable()          { DEFINE_INT_VARIABLE("p_filter_cell_negate_option"); }
    String_Variable_t*  References_Filter_t::Cell_Argument_Variable()               { DEFINE_STRING_VARIABLE("p_filter_cell_argument"); }
    Bool_Variable_t*    References_Filter_t::Cell_Do_Negate_Variable()              { DEFINE_BOOL_VARIABLE("p_filter_cell_do_negate"); }

    Int_Variable_t*     References_Filter_t::Relation_Select_Option_Variable()      { DEFINE_INT_VARIABLE("p_filter_relation_select_option"); }
    Int_Variable_t*     References_Filter_t::Relation_Negate_Option_Variable()      { DEFINE_INT_VARIABLE("p_filter_relation_negate_option"); }
    Int_Variable_t*     References_Filter_t::Relation_Argument_Variable()           { DEFINE_INT_VARIABLE("p_filter_relation_argument"); }
    Bool_Variable_t*    References_Filter_t::Relation_Do_Negate_Variable()          { DEFINE_BOOL_VARIABLE("p_filter_relation_do_negate"); }

    Int_Variable_t*     References_Filter_t::Is_Male_Option_Variable()              { DEFINE_INT_VARIABLE("p_filter_is_male_option"); }
    Int_Variable_t*     References_Filter_t::Is_Female_Option_Variable()            { DEFINE_INT_VARIABLE("p_filter_is_female_option"); }
    Int_Variable_t*     References_Filter_t::Male_Female_Ternary_Variable()         { DEFINE_INT_VARIABLE("p_filter_male_female_ternary"); }

    Int_Variable_t*     References_Filter_t::Is_Unique_Option_Variable()            { DEFINE_INT_VARIABLE("p_filter_is_unique_option"); }
    Int_Variable_t*     References_Filter_t::Is_Generic_Option_Variable()           { DEFINE_INT_VARIABLE("p_filter_is_generic_option"); }
    Int_Variable_t*     References_Filter_t::Unique_Generic_Ternary_Variable()      { DEFINE_INT_VARIABLE("p_filter_unique_generic_ternary"); }

    Int_Variable_t*     References_Filter_t::In_Interior_Option_Variable()          { DEFINE_INT_VARIABLE("p_filter_in_interior_option"); }
    Int_Variable_t*     References_Filter_t::In_Exterior_Option_Variable()          { DEFINE_INT_VARIABLE("p_filter_in_exterior_option"); }
    Int_Variable_t*     References_Filter_t::Interior_Exterior_Ternary_Variable()   { DEFINE_INT_VARIABLE("p_filter_interior_exterior_ternary"); }

    String_t References_Filter_t::Mod_Argument()
    {
        return Mod_Argument_Variable()->Value();
    }

    void References_Filter_t::Mod_Argument(String_t value)
    {
        Mod_Argument_Variable()->Value(value);
    }

    Bool_t References_Filter_t::Mod_Do_Negate()
    {
        return Mod_Do_Negate_Variable()->Value();
    }

    void References_Filter_t::Mod_Do_Negate(Bool_t value)
    {
        Mod_Do_Negate_Variable()->Value(value);
    }

    String_t References_Filter_t::Race_Argument()
    {
        return Race_Argument_Variable()->Value();
    }

    void References_Filter_t::Race_Argument(String_t value)
    {
        Race_Argument_Variable()->Value(value);
    }

    Bool_t References_Filter_t::Race_Do_Negate()
    {
        return Race_Do_Negate_Variable()->Value();
    }

    void References_Filter_t::Race_Do_Negate(Bool_t value)
    {
        Race_Do_Negate_Variable()->Value(value);
    }

    String_t References_Filter_t::Base_Argument()
    {
        return Base_Argument_Variable()->Value();
    }

    void References_Filter_t::Base_Argument(String_t value)
    {
        Base_Argument_Variable()->Value(value);
    }

    Bool_t References_Filter_t::Base_Do_Negate()
    {
        return Base_Do_Negate_Variable()->Value();
    }

    void References_Filter_t::Base_Do_Negate(Bool_t value)
    {
        Base_Do_Negate_Variable()->Value(value);
    }

    String_t References_Filter_t::Name_Argument()
    {
        return Name_Argument_Variable()->Value();
    }

    void References_Filter_t::Name_Argument(String_t value)
    {
        Name_Argument_Variable()->Value(value);
    }

    Bool_t References_Filter_t::Name_Do_Negate()
    {
        return Name_Do_Negate_Variable()->Value();
    }

    void References_Filter_t::Name_Do_Negate(Bool_t value)
    {
        Name_Do_Negate_Variable()->Value(value);
    }

    String_t References_Filter_t::Location_Argument()
    {
        return Location_Argument_Variable()->Value();
    }

    void References_Filter_t::Location_Argument(String_t value)
    {
        Location_Argument_Variable()->Value(value);
    }

    Bool_t References_Filter_t::Location_Do_Negate()
    {
        return Location_Do_Negate_Variable()->Value();
    }

    void References_Filter_t::Location_Do_Negate(Bool_t value)
    {
        Location_Do_Negate_Variable()->Value(value);
    }

    String_t References_Filter_t::Cell_Argument()
    {
        return Cell_Argument_Variable()->Value();
    }

    void References_Filter_t::Cell_Argument(String_t value)
    {
        Cell_Argument_Variable()->Value(value);
    }

    Bool_t References_Filter_t::Cell_Do_Negate()
    {
        return Cell_Do_Negate_Variable()->Value();
    }

    void References_Filter_t::Cell_Do_Negate(Bool_t value)
    {
        Cell_Do_Negate_Variable()->Value(value);
    }

    Relation_e References_Filter_t::Relation_Argument()
    {
        return Relation_Argument_Variable()->Value();
    }

    void References_Filter_t::Relation_Argument(Relation_e value)
    {
        Relation_Argument_Variable()->Value(value);
    }

    String_t References_Filter_t::Relation_Argument_String()
    {
        Relation_e relation = Relation_Argument();
        if (relation == Relation_e::NONE) {
            return " Any ";
        } else {
            return (std::string(" ") + Relation_e::To_String(relation) + " ").c_str();
        }
    }

    Bool_t References_Filter_t::Relation_Do_Negate()
    {
        return Relation_Do_Negate_Variable()->Value();
    }

    void References_Filter_t::Relation_Do_Negate(Bool_t value)
    {
        Relation_Do_Negate_Variable()->Value(value);
    }

    Ternary_e References_Filter_t::Male_Female_Ternary()
    {
        return Male_Female_Ternary_Variable()->Value();
    }

    void References_Filter_t::Male_Female_Ternary(Ternary_e value)
    {
        Male_Female_Ternary_Variable()->Value(value);
    }

    Ternary_e References_Filter_t::Unique_Generic_Ternary()
    {
        return Unique_Generic_Ternary_Variable()->Value();
    }

    void References_Filter_t::Unique_Generic_Ternary(Ternary_e value)
    {
        Unique_Generic_Ternary_Variable()->Value(value);
    }

    Ternary_e References_Filter_t::Interior_Exterior_Ternary()
    {
        return Interior_Exterior_Ternary_Variable()->Value();
    }

    void References_Filter_t::Interior_Exterior_Ternary(Ternary_e value)
    {
        Interior_Exterior_Ternary_Variable()->Value(value);
    }

    Vector_t<Loaded_Actor_t>& References_Filter_t::Execute(Vector_t<Loaded_Actor_t>* read, Vector_t<Loaded_Actor_t>* write)
    {
        Vector_t<Loaded_Actor_t>* temp = nullptr;
        auto Swap = [&temp, &read, &write]()->void
        {
            temp = read;
            read = write;
            write = temp;
            write->resize(0);
        };

        auto Filter_Search = [&read, &write, &Swap](String_t search,
                                                    Bool_t do_negate,
                                                    Ternary_e(*is_match)(Actor_t*, Cell_t*, String_t))->void
        {
            if (search.data && search.data[0]) {
                if (do_negate) {
                    for (Index_t idx = 0, end = read->size(); idx < end; idx += 1) {
                        Loaded_Actor_t& loaded_actor = read->at(idx);
                        Actor_t* actor = loaded_actor.actor;
                        Cell_t* cell = loaded_actor.cell;
                        if (actor && cell && is_match(actor, cell, search) == Ternary_e::LOW) {
                            write->push_back(loaded_actor);
                        }
                    }
                } else {
                    for (Index_t idx = 0, end = read->size(); idx < end; idx += 1) {
                        Loaded_Actor_t& loaded_actor = read->at(idx);
                        Actor_t* actor = loaded_actor.actor;
                        Cell_t* cell = loaded_actor.cell;
                        if (actor && cell && is_match(actor, cell, search) == Ternary_e::HIGH) {
                            write->push_back(loaded_actor);
                        }
                    }
                }
                Swap();
            }
        };

        Filter_Search(
            Mod_Argument(),
            Mod_Do_Negate(),
            [](Actor_t* actor, Cell_t* cell, String_t search)->Ternary_e
            {
                Actor_Base_t* actor_base = static_cast<Actor_Base_t*>
                    (actor->base_form);
                if (actor_base && actor_base->form_files) {
                    for (Index_t idx = 0, end = actor_base->form_files->count; idx < end; idx += 1) {
                        skylib::Mod_t* mod = actor_base->form_files->entries[idx];
                        if (mod) {
                            if (strlen(search) > 1) {
                                if (skylib::CString_t::Contains(mod->Name(), search, true)) {
                                    return Ternary_e::HIGH;
                                }
                            } else {
                                if (skylib::CString_t::Starts_With(mod->Name(), search, true)) {
                                    return Ternary_e::HIGH;
                                }
                            }
                        }
                    }
                    return Ternary_e::LOW;
                } else {
                    return Ternary_e::NONE;
                }
            }
        );

        Filter_Search(
            Race_Argument(),
            Race_Do_Negate(),
            [](Actor_t* actor, Cell_t* cell, String_t search)->Ternary_e
            {
                Race_t* race = actor->Race();
                if (race) {
                    if (strlen(search) > 1) {
                        if (skylib::CString_t::Contains(race->Name(), search, true) ||
                            skylib::CString_t::Contains(race->Get_Editor_ID(), search, true) ||
                            skylib::CString_t::Contains(race->Form_ID_String(), search, true)) {
                            return Ternary_e::HIGH;
                        } else {
                            return Ternary_e::LOW;
                        }
                    } else {
                        if (skylib::CString_t::Starts_With(race->Name(), search, true) ||
                            skylib::CString_t::Starts_With(race->Get_Editor_ID(), search, true) ||
                            skylib::CString_t::Starts_With(race->Form_ID_String(), search, true)) {
                            return Ternary_e::HIGH;
                        } else {
                            return Ternary_e::LOW;
                        }
                    }
                } else {
                    return Ternary_e::NONE;
                }
            }
        );

        Filter_Search(
            Base_Argument(),
            Base_Do_Negate(),
            [](Actor_t* actor, Cell_t* cell, String_t search)->Ternary_e
            {
                Actor_Base_t* actor_base = static_cast<Actor_Base_t*>
                    (actor->base_form);
                if (actor_base) {
                    if (strlen(search) > 1) {
                        if (skylib::CString_t::Contains(actor_base->Name(), search, true) ||
                            skylib::CString_t::Contains(actor_base->Get_Editor_ID(), search, true) ||
                            skylib::CString_t::Contains(actor_base->Form_ID_String(), search, true)) {
                            return Ternary_e::HIGH;
                        } else {
                            return Ternary_e::LOW;
                        }
                    } else {
                        if (skylib::CString_t::Starts_With(actor_base->Name(), search, true) ||
                            skylib::CString_t::Starts_With(actor_base->Get_Editor_ID(), search, true) ||
                            skylib::CString_t::Starts_With(actor_base->Form_ID_String(), search, true)) {
                            return Ternary_e::HIGH;
                        } else {
                            return Ternary_e::LOW;
                        }
                    }
                } else {
                    return Ternary_e::NONE;
                }
            }
        );

        Filter_Search(
            Name_Argument(),
            Name_Do_Negate(),
            [](Actor_t* actor, Cell_t* cell, String_t search)->Ternary_e
            {
                if (strlen(search) > 1) {
                    if (skylib::CString_t::Contains(actor->Name(), search, true) ||
                        skylib::CString_t::Contains(actor->Base_Name(), search, true) ||
                        skylib::CString_t::Contains(actor->Get_Editor_ID(), search, true) ||
                        skylib::CString_t::Contains(actor->Form_ID_String(), search, true)) {
                        return Ternary_e::HIGH;
                    } else {
                        return Ternary_e::LOW;
                    }
                } else {
                    if (skylib::CString_t::Starts_With(actor->Name(), search, true) ||
                        skylib::CString_t::Starts_With(actor->Base_Name(), search, true) ||
                        skylib::CString_t::Starts_With(actor->Get_Editor_ID(), search, true) ||
                        skylib::CString_t::Starts_With(actor->Form_ID_String(), search, true)) {
                        return Ternary_e::HIGH;
                    } else {
                        return Ternary_e::LOW;
                    }
                }
            }
        );

        Filter_Search(
            Cell_Argument(),
            Cell_Do_Negate(),
            [](Actor_t* actor, Cell_t* cell, String_t search)->Ternary_e
            {
                if (strlen(search) > 1) {
                    if (skylib::CString_t::Contains(cell->Name(), search, true) ||
                        skylib::CString_t::Contains(cell->Get_Editor_ID(), search, true) ||
                        skylib::CString_t::Contains(cell->Form_ID_String(), search, true)) {
                        return Ternary_e::HIGH;
                    } else {
                        return Ternary_e::LOW;
                    }
                } else {
                    if (skylib::CString_t::Starts_With(cell->Name(), search, true) ||
                        skylib::CString_t::Starts_With(cell->Get_Editor_ID(), search, true) ||
                        skylib::CString_t::Starts_With(cell->Form_ID_String(), search, true)) {
                        return Ternary_e::HIGH;
                    } else {
                        return Ternary_e::LOW;
                    }
                }
            }
        );

        {
            Relation_e relation = Relation_Argument();
            if (relation != Relation_e::NONE) {
                Actor_Base_t* player_actor_base = Consts_t::Skyrim_Player_Actor_Base();
                for (Index_t idx = 0, end = read->size(); idx < end; idx += 1) {
                    Loaded_Actor_t& loaded_actor = read->at(idx);
                    Actor_t* actor = loaded_actor.actor;
                    Cell_t* cell = loaded_actor.cell;
                    if (actor && cell && actor->base_form && Relation_e::Between(player_actor_base, actor->base_form) == relation) {
                        write->push_back(loaded_actor);
                    }
                }
                Swap();
            }
        }

        auto Filter_Ternary = [&read, &write, &Swap](Ternary_e ternary,
                                                     Bool_t(*is_high)(Actor_t*, Cell_t*),
                                                     Bool_t(*is_low)(Actor_t*, Cell_t*))->void
        {
            if (ternary == Ternary_e::HIGH) {
                for (Index_t idx = 0, end = read->size(); idx < end; idx += 1) {
                    Loaded_Actor_t& loaded_actor = read->at(idx);
                    Actor_t* actor = loaded_actor.actor;
                    Cell_t* cell = loaded_actor.cell;
                    if (actor && cell && is_high(actor, cell)) {
                        write->push_back(loaded_actor);
                    }
                }
                Swap();
            } else if (ternary == Ternary_e::LOW) {
                for (Index_t idx = 0, end = read->size(); idx < end; idx += 1) {
                    Loaded_Actor_t& loaded_actor = read->at(idx);
                    Actor_t* actor = loaded_actor.actor;
                    Cell_t* cell = loaded_actor.cell;
                    if (actor && cell && is_low(actor, cell)) {
                        write->push_back(loaded_actor);
                    }
                }
                Swap();
            }
        };

        Filter_Ternary(
            Male_Female_Ternary(),
            [](Actor_t* actor, Cell_t* cell)->Bool_t
            {
                Actor_Base_t* actor_base = static_cast<Actor_Base_t*>
                    (actor->base_form);
                return actor_base && actor_base->Is_Male();
            },
            [](Actor_t* actor, Cell_t* cell)->Bool_t
            {
                Actor_Base_t* actor_base = static_cast<Actor_Base_t*>
                    (actor->base_form);
                return actor_base && actor_base->Is_Female();
            }
        );

        Filter_Ternary(
            Unique_Generic_Ternary(),
            [](Actor_t* actor, Cell_t* cell)->Bool_t
            {
                Actor_Base_t* actor_base = static_cast<Actor_Base_t*>
                    (actor->base_form);
                return actor_base && actor_base->Is_Unique();
            },
            [](Actor_t* actor, Cell_t* cell)->Bool_t
            {
                Actor_Base_t* actor_base = static_cast<Actor_Base_t*>
                    (actor->base_form);
                return actor_base && actor_base->Is_Generic();
            }
        );

        Filter_Ternary(
            Interior_Exterior_Ternary(),
            [](Actor_t* actor, Cell_t* cell)->Bool_t
            {
                return cell->Is_Interior();
            },
            [](Actor_t* actor, Cell_t* cell)->Bool_t
            {
                return cell->Is_Exterior();
            }
        );

        return *read;
    }

    void References_Filter_t::Clear()
    {
        Mod_Argument("");
        Mod_Do_Negate(false);

        Race_Argument("");
        Race_Do_Negate(false);

        Base_Argument("");
        Base_Do_Negate(false);

        Name_Argument("");
        Name_Do_Negate(false);

        Location_Argument("");
        Location_Do_Negate(false);

        Cell_Argument("");
        Cell_Do_Negate(false);

        Relation_Argument(Relation_e::NONE);
        Relation_Do_Negate(false);

        Male_Female_Ternary(Ternary_e::NONE);
        Unique_Generic_Ternary(Ternary_e::NONE);
        Interior_Exterior_Ternary(Ternary_e::NONE);
    }

    Vector_t<String_t> References_Filter_t::Selectable_Mods()
    {
        Vector_t<Mod_t*> mods = Mod_t::Active_Mods();

        Vector_t<String_t> values;
        values.reserve(mods.size() + 1);

        values.push_back(" Any ");
        for (size_t idx = 0, count = mods.size(); idx < count; idx += 1) {
            values.push_back(mods[idx]->Name());
        }

        return values;
    }

    Vector_t<String_t> References_Filter_t::Selectable_Races()
    {
        Vector_t<Race_t*> races;

        if (Options()->Do_Smart_Select()) {
            races.reserve(Race_t::Race_Count());

            String_t current = Race_Argument();
            Race_Argument("");
            Vector_t<Loaded_Actor_t> loaded_actors = List()->Loaded_Actors();
            Race_Argument(current);

            for (Index_t idx = 0, end = loaded_actors.size(); idx < end; idx += 1) {
                Loaded_Actor_t& loaded_actor = loaded_actors.at(idx);
                Actor_t* actor = loaded_actor.actor;
                Cell_t* cell = loaded_actor.cell;
                if (actor && cell) {
                    Race_t* race = actor->Race();
                    if (race && !races.Has(race)) {
                        races.push_back(race);
                    }
                }
            }
        } else {
            races = Race_t::Races();
        }

        races.Sort(
            [](Race_t** race_a, Race_t** race_b)->Int_t
            {
                const char* name_a = race_a && *race_a ? (*race_a)->Get_Editor_ID() : "";
                const char* name_b = race_b && *race_b ? (*race_b)->Get_Editor_ID() : "";
                return Main_t::String_Comparator(name_a, name_b);
            }
        );

        Vector_t<String_t> values;
        values.reserve(races.size() + 1);

        values.push_back(" Any ");
        for (size_t idx = 0, count = races.size(); idx < count; idx += 1) {
            values.push_back(races[idx]->Get_Editor_ID());
        }

        return values;
    }

    Vector_t<String_t> References_Filter_t::Selectable_Bases()
    {

    }

    Vector_t<String_t> References_Filter_t::Selectable_Names()
    {

    }

    Vector_t<String_t> References_Filter_t::Selectable_Cells()
    {

    }

    Vector_t<String_t> References_Filter_t::Selectable_Relations()
    {

    }

    void References_Filter_t::On_Build_Page(Latent_Callback_i* lcallback)
    {
        Main_t* mcm = Main_t::Self();

        mcm->Title_Text(" Filter References ");

        mcm->Cursor_Position(0);
        mcm->Cursor_Fill_Mode(Cursor_e::LEFT_TO_RIGHT);

        Back_Option_Variable()->Value(mcm->Add_Text_Option(Main_t::BACK_LABEL, ""));
        Clear_Option_Variable()->Value(mcm->Add_Text_Option(Main_t::CLEAR_LABEL, ""));

        mcm->Add_Header_Option(" Mod ");
        mcm->Add_Header_Option("");
        Mod_Search_Option_Variable()->Value(mcm->Add_Input_Option(" Search ", Mod_Argument()));
        Mod_Select_Option_Variable()->Value(mcm->Add_Menu_Option(" Select ", "..."));
        Mod_Negate_Option_Variable()->Value(mcm->Add_Toggle_Option(" Negate ", Mod_Do_Negate()));
        mcm->Add_Empty_Option();

        mcm->Add_Header_Option(" Race ");
        mcm->Add_Header_Option("");
        Race_Search_Option_Variable()->Value(mcm->Add_Input_Option(" Search ", Race_Argument()));
        Race_Select_Option_Variable()->Value(mcm->Add_Menu_Option(" Select ", "..."));
        Race_Negate_Option_Variable()->Value(mcm->Add_Toggle_Option(" Negate ", Race_Do_Negate()));
        mcm->Add_Empty_Option();

        mcm->Add_Header_Option(" Base ");
        mcm->Add_Header_Option("");
        Base_Search_Option_Variable()->Value(mcm->Add_Input_Option(" Search ", Base_Argument()));
        Base_Select_Option_Variable()->Value(mcm->Add_Menu_Option(" Select ", "..."));
        Base_Negate_Option_Variable()->Value(mcm->Add_Toggle_Option(" Negate ", Base_Do_Negate()));
        mcm->Add_Empty_Option();

        mcm->Add_Header_Option(" Name ");
        mcm->Add_Header_Option("");
        Name_Search_Option_Variable()->Value(mcm->Add_Input_Option(" Search ", Name_Argument()));
        Name_Select_Option_Variable()->Value(mcm->Add_Menu_Option(" Select ", "..."));
        Name_Negate_Option_Variable()->Value(mcm->Add_Toggle_Option(" Negate ", Name_Do_Negate()));
        mcm->Add_Empty_Option();

        mcm->Add_Header_Option(" Cell ");
        mcm->Add_Header_Option("");
        Cell_Search_Option_Variable()->Value(mcm->Add_Input_Option(" Search ", Cell_Argument()));
        Cell_Select_Option_Variable()->Value(mcm->Add_Menu_Option(" Select ", "..."));
        Cell_Negate_Option_Variable()->Value(mcm->Add_Toggle_Option(" Negate ", Cell_Do_Negate()));
        mcm->Add_Empty_Option();

        mcm->Add_Header_Option(" Relation ");
        mcm->Add_Header_Option("");
        Relation_Select_Option_Variable()->Value(mcm->Add_Menu_Option(" Select ", Relation_Argument_String()));
        Relation_Negate_Option_Variable()->Value(mcm->Add_Toggle_Option(" Negate ", Relation_Do_Negate()));

        mcm->Add_Header_Option(" Other ");
        mcm->Add_Header_Option("");

        Is_Male_Option_Variable()->Value(mcm->Add_Toggle_Option(" Is Male ", Male_Female_Ternary() == Ternary_e::HIGH));
        Is_Female_Option_Variable()->Value(mcm->Add_Toggle_Option(" Is Female ", Male_Female_Ternary() == Ternary_e::LOW));

        Is_Unique_Option_Variable()->Value(mcm->Add_Toggle_Option(" Is Unique ", Unique_Generic_Ternary() == Ternary_e::HIGH));
        Is_Generic_Option_Variable()->Value(mcm->Add_Toggle_Option(" Is Generic ", Unique_Generic_Ternary() == Ternary_e::LOW));

        In_Interior_Option_Variable()->Value(mcm->Add_Toggle_Option(" In Interior ", Interior_Exterior_Ternary() == Ternary_e::HIGH));
        In_Exterior_Option_Variable()->Value(mcm->Add_Toggle_Option(" In Exterior ", Interior_Exterior_Ternary() == Ternary_e::LOW));

        Options_Offset_Variable()->Value(Back_Option_Variable()->Value());

        mcm->Destroy_Latent_Callback(lcallback);
    }

    void References_Filter_t::On_Option_Select(Int_t option, Latent_Callback_i* lcallback)
    {
        Main_t* mcm = Main_t::Self();

        if (option == Back_Option_Variable()->Value()) {
            mcm->Disable_Option(option);
            Current_View(View_e::LIST);
            mcm->Reset_Page();
        } else if (option == Clear_Option_Variable()->Value()) {
            mcm->Disable_Option(option);
            Clear();
            mcm->Reset_Page();
        }

        mcm->Destroy_Latent_Callback(lcallback);
    }

    void References_Filter_t::On_Option_Menu_Open(Int_t option, Latent_Callback_i* lcallback)
    {
        Main_t* mcm = Main_t::Self();

        if (option == Mod_Select_Option_Variable()->Value()) {
            mcm->Flicker_Option(option);
            mcm->Menu_Dialog_Values(Selectable_Mods());
            mcm->Menu_Dialog_Default(0);
        } else if (option == Race_Select_Option_Variable()->Value()) {
            mcm->Flicker_Option(option);
            mcm->Menu_Dialog_Values(Selectable_Races());
            mcm->Menu_Dialog_Default(0);
        }

        mcm->Destroy_Latent_Callback(lcallback);
    }

    void References_Filter_t::On_Option_Menu_Accept(Int_t option, Int_t idx, Latent_Callback_i* lcallback)
    {
        Main_t* mcm = Main_t::Self();

        if (option == Mod_Select_Option_Variable()->Value()) {
            if (idx > -1) {
                String_t value = "";
                if (idx > 0) {
                    Vector_t<String_t> mods = Selectable_Mods();
                    if (idx < mods.size()) {
                        value = mods[idx];
                    }
                }
                Mod_Argument(value);
                mcm->Input_Option_Value(Mod_Search_Option_Variable()->Value(), value, true);
            }
        } else if (option == Race_Select_Option_Variable()->Value()) {
            if (idx > -1) {
                String_t value = "";
                if (idx > 0) {
                    Vector_t<String_t> races = Selectable_Races();
                    if (idx < races.size()) {
                        value = races[idx];
                    }
                }
                Race_Argument(value);
                mcm->Input_Option_Value(Race_Search_Option_Variable()->Value(), value, true);
            }
        }

        mcm->Destroy_Latent_Callback(lcallback);
    }

    void References_Filter_t::On_Option_Slider_Open(Int_t option, Latent_Callback_i* lcallback)
    {
        Main_t::Self()->Destroy_Latent_Callback(lcallback);
    }

    void References_Filter_t::On_Option_Slider_Accept(Int_t option, Float_t value, Latent_Callback_i* lcallback)
    {
        Main_t::Self()->Destroy_Latent_Callback(lcallback);
    }

    void References_Filter_t::On_Option_Input_Accept(Int_t option, String_t value, Latent_Callback_i* lcallback)
    {
        Main_t* mcm = Main_t::Self();

        if (option == Mod_Search_Option_Variable()->Value()) {
            Mod_Argument(value);
            mcm->Input_Option_Value(option, value, true);
        } else if (option == Race_Search_Option_Variable()->Value()) {
            Race_Argument(value);
            mcm->Input_Option_Value(option, value, true);
        }

        mcm->Destroy_Latent_Callback(lcallback);
    }

    void References_Filter_t::On_Option_Keymap_Change(Int_t option, Int_t key, String_t conflict, String_t mod, Latent_Callback_i* lcallback)
    {
        Main_t::Self()->Destroy_Latent_Callback(lcallback);
    }

    void References_Filter_t::On_Option_Default(Int_t option, Latent_Callback_i* lcallback)
    {
        Main_t::Self()->Destroy_Latent_Callback(lcallback);
    }

    void References_Filter_t::On_Option_Highlight(Int_t option, Latent_Callback_i* lcallback)
    {
        Main_t::Self()->Destroy_Latent_Callback(lcallback);
    }

    /* References_Options_t */

    Int_Variable_t*     References_Options_t::Smart_Select_Option_Variable()    { DEFINE_INT_VARIABLE("p_options_smart_select_option"); }
    Bool_Variable_t*    References_Options_t::Do_Smart_Select_Variable()        { DEFINE_BOOL_VARIABLE("p_options_do_smart_select"); }

    Bool_t References_Options_t::Do_Smart_Select()
    {
        return Do_Smart_Select_Variable()->Value();
    }

    void References_Options_t::Do_Smart_Select(Bool_t value)
    {
        Do_Smart_Select_Variable()->Value(value);
    }

    void References_Options_t::Reset()
    {
        Do_Smart_Select(true);
    }

    void References_Options_t::On_Build_Page(Latent_Callback_i* lcallback)
    {
        Main_t::Self()->Destroy_Latent_Callback(lcallback);
    }

    void References_Options_t::On_Option_Select(Int_t option, Latent_Callback_i* lcallback)
    {
        Main_t::Self()->Destroy_Latent_Callback(lcallback);
    }

    void References_Options_t::On_Option_Menu_Open(Int_t option, Latent_Callback_i* lcallback)
    {
        Main_t::Self()->Destroy_Latent_Callback(lcallback);
    }

    void References_Options_t::On_Option_Menu_Accept(Int_t option, Int_t idx, Latent_Callback_i* lcallback)
    {
        Main_t::Self()->Destroy_Latent_Callback(lcallback);
    }

    void References_Options_t::On_Option_Slider_Open(Int_t option, Latent_Callback_i* lcallback)
    {
        Main_t::Self()->Destroy_Latent_Callback(lcallback);
    }

    void References_Options_t::On_Option_Slider_Accept(Int_t option, Float_t value, Latent_Callback_i* lcallback)
    {
        Main_t::Self()->Destroy_Latent_Callback(lcallback);
    }

    void References_Options_t::On_Option_Input_Accept(Int_t option, String_t value, Latent_Callback_i* lcallback)
    {
        Main_t::Self()->Destroy_Latent_Callback(lcallback);
    }

    void References_Options_t::On_Option_Keymap_Change(Int_t option, Int_t key, String_t conflict, String_t mod, Latent_Callback_i* lcallback)
    {
        Main_t::Self()->Destroy_Latent_Callback(lcallback);
    }

    void References_Options_t::On_Option_Default(Int_t option, Latent_Callback_i* lcallback)
    {
        Main_t::Self()->Destroy_Latent_Callback(lcallback);
    }

    void References_Options_t::On_Option_Highlight(Int_t option, Latent_Callback_i* lcallback)
    {
        Main_t::Self()->Destroy_Latent_Callback(lcallback);
    }

    /* References_Item_t */

    void References_Item_t::On_Build_Page(Latent_Callback_i* lcallback)
    {
        Main_t::Self()->Destroy_Latent_Callback(lcallback);
    }

    void References_Item_t::On_Option_Select(Int_t option, Latent_Callback_i* lcallback)
    {
        Main_t::Self()->Destroy_Latent_Callback(lcallback);
    }

    void References_Item_t::On_Option_Menu_Open(Int_t option, Latent_Callback_i* lcallback)
    {
        Main_t::Self()->Destroy_Latent_Callback(lcallback);
    }

    void References_Item_t::On_Option_Menu_Accept(Int_t option, Int_t idx, Latent_Callback_i* lcallback)
    {
        Main_t::Self()->Destroy_Latent_Callback(lcallback);
    }

    void References_Item_t::On_Option_Slider_Open(Int_t option, Latent_Callback_i* lcallback)
    {
        Main_t::Self()->Destroy_Latent_Callback(lcallback);
    }

    void References_Item_t::On_Option_Slider_Accept(Int_t option, Float_t value, Latent_Callback_i* lcallback)
    {
        Main_t::Self()->Destroy_Latent_Callback(lcallback);
    }

    void References_Item_t::On_Option_Input_Accept(Int_t option, String_t value, Latent_Callback_i* lcallback)
    {
        Main_t::Self()->Destroy_Latent_Callback(lcallback);
    }

    void References_Item_t::On_Option_Keymap_Change(Int_t option, Int_t key, String_t conflict, String_t mod, Latent_Callback_i* lcallback)
    {
        Main_t::Self()->Destroy_Latent_Callback(lcallback);
    }

    void References_Item_t::On_Option_Default(Int_t option, Latent_Callback_i* lcallback)
    {
        Main_t::Self()->Destroy_Latent_Callback(lcallback);
    }

    void References_Item_t::On_Option_Highlight(Int_t option, Latent_Callback_i* lcallback)
    {
        Main_t::Self()->Destroy_Latent_Callback(lcallback);
    }

}}
