#include "main_window.hpp"
#include <iostream>

ascendPS1Window::ascendPS1Window() : vbox(Gtk::ORIENTATION_VERTICAL) {
    set_title("ascendPS1");
    set_default_size(960, 720);

    auto file_menu = Gtk::make_managed<Gtk::MenuItem>("File");
    auto file_submenu = Gtk::make_managed<Gtk::Menu>();
    
    auto open_iso = Gtk::make_managed<Gtk::MenuItem>("Load ISO/BIN/CUE");
    load_iso_item->signal_activate().connect(sigc::mem_fun(*this, &ascendPS1Window::on_menu_load_iso));
    file_submenu->append(*open_iso);

    auto load_ps_exe = Gtk::make_managed<Gtk::MenuItem>("Load PS-EXE");
    load_ps_exe_item->signal_activate().connect(sigc::mem_fun(*this, &ascendPS1Window::on_menu_load_ps_exe));
    file_submenu->append(*load_ps_exe_item);

    auto view_games = Gtk::make_managed<Gtk::MenuItem>("View Games");
    view_games_item->signal_activate().connect(sigc::mem_fun(*this, &ascendPS1Window::on_menu_view_games));
    file_submenu->append(*view_games_item);

    auto save_state = Gtk::make_managed<Gtk::MenuItem>("Save State");
    save_state_item->signal_activate().connect(sigc::mem_fun(*this, &ascendPS1Window::on_menu_save_state));
    file_submenu->append(*save_state_item);

    auto load_state = Gtk::make_managed<Gtk::MenuItem>("Load State");
    load_state_item->signal_activate().connect(sigc::mem_fun(*this, &ascendPS1Window::on_menu_load_state));
    file_submenu->append(*load_state_item);

    auto changeslot = Gtk::make_managed<Gtk::MenuItem>("Change Slot");
    changeslot_item->signal_activate().connect(sigc::mem_fun(*this, &ascendPS1Window::on_menu_change_slot));
    file_submenu->append(*changeslot_item);

    auto local_netplay = Gtk::make_managed<Gtk::MenuItem>("Local Netplay");
    local_netplay_item->signal_activate().connect(sigc::mem_fun(*this, &ascendPS1Window::on_menu_local_netplay));
    file_submenu->append(*local_netplay_item);

    auto change_disc = Gtk::make_managed<Gtk::MenuItem>("Change Disc");
    change_disc_item->signal_activate().connect(sigc::mem_fun(*this, &ascendPS1Window::on_menu_change_disc));
    file_submenu->append(*change_disc_item);

    auto exit_item = Gtk::make_managed<Gtk::MenuItem>("Exit");
    exit_item->signal_activate().connect(sigc::mem_fun(*this, &ascendPS1Window::on_menu_exit));
    file_submenu->append(*exit_item);

    file_menu->set_submenu(*file_submenu);
    menu_bar.append(*file_menu);

    auto system_menu = Gtk::make_managed<Gtk::MenuItem>("System");
    auto system_submenu = Gtk::make_managed<Gtk::Menu>();

    auto reset_item = Gtk::make_managed<Gtk::MenuItem>("Reset");
    reset_item->signal_activate().connect(sigc::mem_fun(*this, &ascendPS1Window::on_menu_reset));
    system_submenu->append(*reset_item);

    auto pause_resume_item = Gtk::make_managed<Gtk::MenuItem>("Pause/Resume");
    pause_resume_item->signal_activate().connect(sigc::mem_fun(*this &ascendPS1Window::on_menu_pause_resume));
    system_submenu->append(*pause_resume_item);

    auto soft_reset_item = Gtk::make_managed<Gtk::MenuItem>("Soft Reset");
    soft_reset_item->signal_activate().connect(sigc::mem_fun(*this &ascendPS1Window::on_menu_soft_reset));
    system_submenu->append(*soft_reset_item);

    auto hard_reset_item = Gtk::make_managed<Gtk::MenuItem>("Hard Reset");
    hard_reset_item->signal_activate().connect(sigc::mem_fun(*this &ascendPS1Window::on_menu_hard_reset));
    system_submenu->append(*hard_reset_item);

    auto power_off_item = Gtk::make_managed<Gtk::MenuItem>("Power Off");
    power_off_item->signal_activate().connect(sigc::mem_fun(*this &ascendPS1Window::on_menu_power_off));
    system_submenu->append(*power_off_item);

    system_menu->set_submenu(*system_submenu);
    menu_bar.append(*system_menu);

    auto settings_menu = Gtk::make_managed<Gtk::MenuItem>("Settings");
    auto settings_submenu = Gtk::make_managed<Gtk::Menu>();

    auto bios_item = Gtk::make_managed<Gtk::MenuItem>("BIOS");
    bios_item->signal_activate().connect(sigc::mem_fun(*this &ascendPS1Window::on_menu_bios));
    bios_submenu->append(*bios_item);

    auto region_item = Gtk::make_managed<Gtk::MenuItem>("Region");
    region_item->signal_activate().connect(sigc::mem_fun(*this &ascendPS1Window::on_menu_region));
    region_submenu->append(*region_item);

    auto languages_item = Gtk::make_managed<Gtk::MenuItem>("Languages");
    region_item->signal_activate().connect(sigc::mem_fun(*this &ascendPS1Window::on_menu_languages));
    region_submenu->append(*languages_item);

    auto save_path_config_item = Gtk::make_managed<Gtk::MenuItem>("Save Path Config");
    save_path_config_item->signal_activate().connect(sigc::mem_fun(*this ascendPS1Window::on_menu_save_path_config));
    save_path_config_submenu->append(*save_path_config_item);

    auto screenshot_folder_item = Gtk::make_managed<Gtk::MenuItem>("Screenshot Folder");
    screenshot_folder_item->signal_activate().connect(sigc::mem_fun(*this ascendPS1Window::on_menu_screenshot_folder));
    screenshot_folder_submenu->append(*screenshot_folder_item);

    settings_menu->set_submenu(*settings_submenu);
    menu_bar.append(*settings_menu);

    auto video_menu = Gtk::make_managed<Gtk::MenuItem>("Video");
    auto video_submenu = Gtk::make_managed<Gtk::Menu>();

    auto resolution_item = Gtk::make_managed<Gtk::MenuItem>("Resolution");
    resolution_item->signal_activate().connect(sigc::mem_fun(*this ascendPS1Window::on_menu_resolution));
    resolution_submenu->append(*resolution_item)

    auto aspect_ratio_item = Gtk::make_managed<Gtk::MenuItem>("Aspect Ratio");
    aspect_ratio_item->signal_activate().connect(sigc::mem_fun(*this ascendPS1Window::on_menu_aspect_ratio));
    aspect_ratio_submenu->append(*aspect_ratio_item);

    auto v_sync_on_off_item = Gtk::make_managed<Gtk::MenuItem>("VSync On/Off");
    v_sync_on_off_item->signal_activate().connect(sigc::mem_fun(*this ascendPS1Window::on_menu_v_sync_on_off));
    v_sync_on_off_submenu->append(*v_sync_on_off_item);

    auto filters_item = Gtk::make_managed<Gtk::MenuItem>("Filters");
    filters_item->signal_activate().connect(sigc::mem_fun(*this ascendPS1Window::on_menu_filters));
    filters_submenu->append(*filters_menu);

    auto renderer_item = Gtk::make_managed<Gtk::MenuItem>("Renderer");
    renderer_item->signal_activate().connect(sigc::mem_fun(*this ascendPS1Window::on_menu_renderer));
    renderer_submenu->append(*renderer_item);

    video_menu->set_submenu(*video_submenu);
    menu_bar.append(*video_menu);

    auto audio_menu = Gtk::make_managed<Gtk::MenuItem>("Audio");
    auto audio_submenu = Gtk::make_managed<Gtk::Menu>();

    auto volume_control_item = Gtk::make_managed<Gtk::MenuItem>("Volume Control");
    volume_control_item->signal_activate().connect(sigc::mem_fun(*this ascendPS1Window::on_menu_volume_control));
    volume_control_submenu->append(*volume_control_item);

    auto output_backend_item = Gtk::make_managed<Gtk::MenuItem>("Output Backend");
    output_backend_item->signal_activate().connect(sigc::mem_fun(*this ascendPS1Window::on_menu_output_backend));
    output_backend_submenu->append(*output_backend_item);

    auto enable_reverb_interpolation_item = Gtk::make_managed<Gtk::MenuItem>("Enable Reverb / Interpolation");
    enable_reverb_interpolation_item->signal_activate().connect(sigc::mem_fun(*this ascendPS1Window::on_menu_enable_reverb_interpolation));
    enable_reverb_interpolation_submenu->append(*enable_reverb_interpolation_item);

    auto audio_latency_item = Gtk::make_managed<Gtk::MenuItem>("Audio Latency");
    audio_latency_item->signal_activate().connect(sigc::mem_fun(*this ascendPS1Window::on_menu_audio_latency));
    audio_latency_submenu->append(*audio_latency_item);

    audio_menu->set_submenu(*audio_submenu);
    menu_bar.append(*audio_menu);

    auto controls_menu = Gtk::make_managed<Gtk::MenuItem>("Controls");
    auto controls_submenu = Gtk::make_managed<Gtk::Menu>();

    auto input_mapping_item = Gtk::make_managed<Gtk::MenuItem>("Input Mapping");
    input_mapping_item->signal_activate().connect(sigc::mem_fun(*this ascendPS1Window::on_menu_input_mapping));
    input_mapping_submenu->append(*input_mapping_item);

    auto enable_analog_mode_item = Gtk::make_managed<Gtk::MenuItem>("Enable Analog Mode");
    enable_analog_mode_item->signal_activate().connect(sigc::mem_fun(*this ascendPS1Window::on_menu_enable_analog_mode));
    enable_analog_mode_submenu->append(*enable_analog_mode_item);

    auto rumble_support_item = Gtk::make_managed<Gtk::MenuItem>("Rumble Support");
    rumble_support_item->signal_activate().connect(sigc::mem_fun(*this ascendPS1Window::on_menu_rumble_support));
    rumble_support_submenu->append(*rumble_support_item);

    auto auto_fire_settings_item = Gtk::make_managed<Gtk::MenuItem>("Auto Fire Settings");
    auto_fire_settings_item->signal_activate().connect(sigc::mem_fun(*this ascendPS1Window::on_menu_auto_fire_settings));
    auto_fire_settings_submenu->append(*auto_fire_settings_item);

    controls_menu->set_submenu(*controls_submenu);
    menu_bar.append(*controls_menu);

    auto memory_card_menu = Gtk::make_managed<Gtk::MenuItem>("Memory Card");
    auto memory_card_submenu = Gtk::make_managed<Gtk::Menu>();

    auto manage_cards_item = Gtk::make_managed<Gtk::MenuItem>("Manage Cards");
    manage_cards_item->signal_activate().connect(sigc::mem_fun(*this ascendPS1Window::on_menu_manage_cards));
    memory_card_submenu->append(*manage_cards_item);

    auto import_export_save_file_item = Gtk::make_managed<Gtk::MenuItem>("Import/Export Save File");
    import_export_save_file_item->signal_activate().connect(sigc::mem_fun(*this ascendPS1Window::on_menu_import_export_save_file));
    memory_card_submenu->append(*import_export_save_file_item);

    auto backup_all_saves_item = Gtk::make_managed<Gtk::MenuItem>("Backup All Saves");
    backup_all_saves_item->signal_activate().connect(sigc::mem_fun(*this ascendPS1Window::on_menu_backup_all_saves));
    memory_card_submenu->append(*backup_all_saves_item);

    auto restore_all_saves_item = Gtk::make_managed<Gtk::MenuItem>("Restore All Saves");
    restore_all_saves_item->signal_activate().connect(sigc::mem_fun(*this ascendPS1Window::on_menu_restore_all_saves));
    memory_card_submenu->append(*restore_all_saves_item);

    memory_card_menu->set_submenu(*memory_card_submenu);
    menu_bar.append(*memory_card_menu);

    auto cheats_menu = Gtk::make_managed<Gtk::MenuItem>("Cheats");
    auto cheats_submenu = Gtk::make_managed<Gtk::Menu>();

    auto load_cheat_file_cht_ini_item = Gtk::make_managed<Gtk::MenuItem>("Load Cheat File (.cht/.ini)");
    load_cheat_file_cht_ini_item->signal_activate().connect(sigc::mem_fun(*this ascendPS1Window::on_menu_load_cheat_file_cht_ini));
    cheats_submenu->append(*load_cheat_file_cht_ini_item);

    auto enable_disable_cheats_item = Gtk::make_managed<Gtk::MenuItem>("Enable/Disable Cheats");
    enable_disable_cheats_item->signal_activate().connect(sigc::mem_fun(*this ascendPS1Window::on_menu_enable_disable_cheats));
    cheats_submenu->append(*enable_disable_cheats_item);

    auto add_new_cheat_item = Gtk::make_managed<Gtk::MenuItem>("Add New Cheat (Manual Entry)");
    add_new_cheat_item->signal_activate().connect(sigc::mem_fun(*this ascendPS1Window::on_menu_add_new_cheat));
    cheats_submenu->append(*add_new_cheat_item);

    auto search_memory_item = Gtk::make_managed<Gtk::MenuItem>("Search Memory (basic GameShark-like)");
    search_memory_item->signal_activate().connect(sigc::mem_fun(*this ascendPS1Window::on_menu_search_memory));
    cheats_submenu->append(*search_memory_item);

    cheats_menu->set_submenu(*cheats_submenu);
    menu_bar.append(*cheats_menu);

    auto tools_developer_menu = Gtk::make_managed<Gtk::MenuItem>("Tools/Developer");
    auto tools_developer_submenu = Gtk::make_managed<Gtk::Menu>();

    auto debugger_item = Gtk::make_managed<Gtk::MenuItem>("Debugger");
    debugger_item->signal_activate().connect(sigc::mem_fun(*this ascendPS1Window::on_menu_debugger));
    tools_developer_submenu->append(*debugger_item);

    auto disassembler_item = Gtk::make_managed<Gtk::MenuItem>("Disassembler");
    disassembler_item->signal_activate().connect(sigc::mem_fun(*this ascendPS1Window::on_menu_disassembler));
    tools_developer_submenu->append(*disassembler_item);

    auto frame_advance_item = Gtk::make_managed<Gtk::MenuItem>("Frame Advance");
    frame_advance_item->signal_activate().connect(sigc::mem_fun(*this ascendPS1Window::on_menu_frame_advance));
    tools_developer_submenu->append(*frame_advance_item);

    auto log_viewer_item = Gtk::make_managed<Gtk::MenuItem>("Log Viewer");
    log_viewer_item->signal_activate().connect(sigc::mem_fun(*this ascendPS1Window::on_menu_log_viewer));
    tools_developer_submenu->append(*log_viewer_item);

    auto dump_vram_spu_gpu item = Gtk::make_managed<Gtk::MenuItem>("Dump VRAM / SPU / GPU");
    dump_vram_spu_gpu item->signal_activate().connect(sigc::mem_fun(*this ascendPS1Window::on_menu_dump_vram_spu_gpu));
    tools_developer_submenu->append(*dump_vram_spu_gpu item);

    tools_developer_menu->set_submenu(*tools_developer_submenu);
    menu_bar.append(*tools_developer_menu);

    auto help_menu = Gtk::make_managed<Gtk::MenuItem>("Help");
    auto help_submenu = Gtk::make_managed<Gtk::Menu>();

    auto about_item = Gtk::make_managed<Gtk::MenuItem>("About");
    about_item->signal_activate().connect(sigc::mem_fun(*this ascendPS1Window::on_menu_about));
    help_submenu->append(*about_item);

    auto check_for_updates_item = Gtk::make_managed<Gtk::MenuItem>("Check for Updates");
    check_for_updates_item->signal_activate().connect(sigc::mem_fun(*this ascendPS1Window::on_menu_check_for_updates));
    help_submenu->append(*check_for_updates_item);

    auto view_log_files_item = Gtk::make_managed<Gtk::MenuItem>("View Log Files");
    view_log_files_item->signal_activate().connect(sigc::mem_fun(*this ascendPS1Window::on_menu_view_log_files));    
    help_submenu->append(*view_log_files_item);

    auto documentation_FAQ_item = Gtk::make_managed<Gtk::MenuItem>("Documentation / FAQ");
    documentation_FAQ_item->signal_activate().connect(sigc::mem_fun(*this ascendPS1Window::on_menu_documentation_FAQ));
    help_submenu->append(*documentation_FAQ_item);

    auto report_bug_item = Gtk::make_managed<Gtk::MenuItem>("Report Bug");
    report_bug_item->signal_activate().connect(sigc::mem_fun(*this ascendPS1Window::on_menu_report_bug));
    help_submenu->append(*report_bug_item);

    help_menu->set_submenu(*help_submenu);
    menu_bar.append(*help_menu);

    vbox.pack_start(menu_bar, Gtk::PACK_SHRINK);
    vbox.pack_start(output_area);
    add(vbox);

    show_all_children();
}

void ascendPS1Window::on_menu_open_iso() {
    Gtk::FileChooserDialog dialog("Open ISO", Gtk::FILE_CHOOSER_ACTION_OPEN);
    dialog.set_transient_for(*this);
    dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
    dialog.add_button("_Open", Gtk::RESPONSE_OK);

    auto filter = Gtk::FileFilter::create();
    filter->set_name("PlayStation ISOs");
    filter->add_pattern("*.bin");
    filter->add_pattern("*.iso");
    dialog.add_filter(filter);

    if (dialog.run() == Gtk::RESPONSE_OK) {
        std::cout << "Selected ISO: " << dialog.get_filename() << std::endl;
    }
}

void ascendPS1Window::on_menu_exit() {
    hide();
}
