

<?php
  // i have done few changes 
 function taxo_page($form, &$form_state){
 	// $items['taxonomy']=array(
  //       '#title' => 'Enter the taxonomy term ',
  //       '#type' => 'textfield',
  //       '#description' => t('Enter the Taxonomy'),
 	// );


     // $xnxs  = taxonomy_vocabulary_get_names();
     // $list_of_vocobulary = drupal_map_assoc(array());     // drupal_map_assoc($list_of_vocobulary);
     // foreach ($xnxs as $key => $xnx) {
     // watchdog("xnx", '<pre>' . print_r( $xnx, true) . '</pre>');
     // $list_of_vocobulary[] = $xnx->name;
     // }
     // watchdog("list_of_vocobulary", '<pre>' . print_r( $list_of_vocobulary, true) . '</pre>');

 	// $terms = taxonomy_get_tree('vid');
 	// watchdog("terms", '<pre>' . print_r( $terms, true) . '</pre>');

  //   $active = arg(2);
  //   $active_parents = taxonomy_get_parents_all($active);
 	//   watchdog("active_parents", '<pre>' . print_r( $active_parents, true) . '</pre>');

 	// $results = db_query("SELECT *  FROM {taxonomy_term_data}")->fetchAll();
  // watchdog("taxonomy_term_data", '<pre>' . print_r( $results, true) . '</pre>');

  // $list_of_vocobulary = drupal_map_assoc(array());
 	/////#########     this is woking part of the code #######################



 	$results1 = array();
  $list_of_vocobulary = array();
  $results1 = db_query("SELECT machine_name FROM {taxonomy_vocabulary}")->fetchAll();
 	foreach ($results1 as $key => $resu) {
 		$list_of_vocobulary[] =  $resu->machine_name;
  	}

   $option =  $list_of_vocobulary;
#########        just noe un comment
  	// drupal_map_assoc($list_of_vocobulary);
  	// $option= (object)$list_of_vocobulary;
###########

   $xxxx = taxonomy_get_vocabularies();
   $yyyy =  array();
   foreach ($xxxx as $xxxxs) {
      $yyyy[$xxxxs->machine_name] = $xxxxs->machine_name;
      watchdog("yyyy", '<pre>' . print_r( $yyyy, true) . '</pre>');

     # code...
   }
    

   $test_one =  $results1;
   // $test_ones = json_decode(json_encode($test_one), true);
   $test_ones=  $test_one;
   watchdog("test_ones", '<pre>' . print_r( $test_ones, true) . '</pre>');



 	// $list_of_vocobulary =  json_decode(json_encode($list_of_vocobulary),true);
  	   watchdog("list_of_vocobulary", '<pre>' . print_r( $list_of_vocobulary, true) . '</pre>');
 	/////#########     this is woking part of the code   #######################
  	   watchdog("As an Object", '<pre>' . print_r( $option, true) . '</pre>');




  //   $results2 = db_query("SELECT * FROM {taxonomy_index}")->fetchAll();
  //   watchdog("taxonomy_index", '<pre>' . print_r( $results2, true) . '</pre>');

    $results3 = db_query("SELECT tid FROM {taxonomy_term_hierarchy}")->fetchAll();
    foreach ($results3 as $key => $value) {
    watchdog("taxonomy_term_hierarchy", '<pre>' . print_r( $value, true) . '</pre>');
    }



// $tids = array(3);
// $result = taxonomy_select_nodes($tids);
// $titles = array();
// foreach($result as $nid) {
//    $node = node_load($nid);
//    $titles[] = $node->title;
//        watchdog("titles", '<pre>' . print_r( $titles, true) . '</pre>');
// }
 
  // $one = drupal_map_assoc(array());
  $one = array();
  $vocos = taxonomy_get_vocabularies();
  foreach ($vocos as $key => $voco) {
  	 watchdog("voco", '<pre>' . print_r( $voco, true) . '</pre>');
  	 $one[] = $voco->vid;
  	 watchdog("one", '<pre>' . print_r( $one, true) . '</pre>');

  }

     watchdog("one at outside ", '<pre>' . print_r( $one, true) . '</pre>');


  // $voc0_ques = db_query("SELECT name FROM {taxonomy_vocabulary}")->fetchAll();
  // // foreach ($voc0_ques as $key => $voc0_que) {
  // // }
  //  watchdog("voc0_ques", '<pre>' . print_r( $voc0_ques, true) . '</pre>');



  // $req_array = json_decode(json_encode($voc0_ques), True);
  // 	 watchdog("req_array", '<pre>' . print_r( $req_array, true) . '</pre>');


$selected = isset($form_state['taxo']['voco_types']) ? $form_state['taxo']['voco_types'] : key($one);


 // $option_first = _first_dropdown_option();

$option_first =  drupal_map_assoc($selected);
  	 watchdog("option_first", '<pre>' . print_r( $option_first, true) . '</pre>');



$form['taxo']['voco_types'] = array(
  '#title' => t('vocobulary Types'),
  '#type' => 'select',
  '#options' => $yyyy,
   // '#options' => $test_ones,
  '#default_value' => $selected,
  '#validated' => TRUE,
  '#ajax' => array(
        'callback' => 'dropdown_onclick_function',
        'wrapper'  => 'Content_titles-replace',
        'event'    => 'change',
        'method'   => 'replace',
        'effect'   => 'fade',
        ), 
);

$form['taxo']['terms_types'] = array(
  '#title' => t('Terms Types'),
  '#type' => 'select',
  '#options' => '',
    '#multiple' => TRUE,
  '#validated' => TRUE,
    '#prefix' => '<div id="Content_titles-replace">',
  '#suffix' => '</div>',
  '#options' => '<div id="Content_titles-replace">', 
  '#ajax' => array(
        'callback' => 'dropdown_secons_onclick_function',
        'wrapper'  => 'Node_titles-replace',
        'event'    => 'change',
        'method'   => 'replace',
        'effect'   => 'fade',
        ), 
);

$form['taxo']['list_of_the_nodes'] = array(
  '#title' => t('Node list'),
  '#type' => 'select',
  '#options' => '',
    '#multiple' => TRUE,
  '#prefix' => '<div id="Node_titles-replace">',
  '#suffix' => '</div>',
  '#options' => '<div id="Node_titles-replace">', 
  '#validated' => TRUE,
);

$form['taxo']['submit'] = array(
    '#type'  => 'submit',
    '#value' => t('Submit'),
  );

 	// $terms = taxonomy_get_term_by_name('india',$vocabulary = NULL);
  //   watchdog("terms", '<pre>' . print_r( $terms, true) . '</pre>');
  //   $typesArr =  array();
  //   foreach($terms as $term){
  //   	  $typesArr[$content->name] = $term->name;
  //   }
  //   watchdog("typesArr", '<pre>' . print_r( $typesArr, true) . '</pre>');

 	return $form;
 }

 function taxo_page_submit($form, &$form_state){
  $termValue23 = $form_state['values']['terms_types'];
  watchdog("termValue->name", '<pre>' . print_r( $termValue->name, true) . '</pre>');
  watchdog("termValue", '<pre>' . print_r( $termValue, true) . '</pre>');

  $inter = node_load($termValue23);
    watchdog("inter", '<pre>' . print_r( $inter, true) . '</pre>');

 
  // $dhana = $final_taxo[$termValue];
  // watchdog("dhana", '<pre>' . print_r( $dhana, true) . '</pre>');

   $kan = taxonomy_select_nodes($termValue);
   foreach ($kan as $key => $nid) {
     # code...
    $node90 = node_load($nid);
    $title_node[] = $node90->title;

    watchdog("title_node", '<pre>' . print_r( $title_node, true) . '</pre>');

   }

  $form_state['redirect'] = array
(
  // 'admin/mycontent/test',
  'admin/mycontent/result'
  // array
  // (
  //   'query' => $form_state['values']['terms_types']
  // ),
);
 }
   
   function dropdown_secons_onclick_function($form,&$form_state){

      $selVals_node= $form_state['values']['terms_types'];
      watchdog("selVals_node", '<pre>' . print_r( $selVals_node, true) . '</pre>');

      $node_tit = entity_load('taxonomy_term', FALSE, array('name' => $selVals_node));
     watchdog("node_tit", '<pre>' . print_r( $node_tit, true) . '</pre>');


       $selVals_node_ids= db_query('SELECT tid FROM {taxonomy_term_data} WHERE name = :name', array(':name' =>$selVals_node))->fetchAll();
   watchdog("selVals_node_ids", '<pre>' . print_r( $selVals_node_ids, true) . '</pre>');
   watchdog("selVals_node_ids->vid", '<pre>' . print_r( $selVals_node_ids->vid, true) . '</pre>');


      $tree = taxonomy_get_tree($selVals_node);
    watchdog("tree", '<pre>' . print_r( $tree, true) . '</pre>');  



   
 $selVals_node_ids_refines = array();
 foreach ($selVals_node_ids as $selVals_node_id) {
  $selVals_node_ids_refines[$selVals_node_id->tid] = $selVals_node_id->tid;
  watchdog("selVals_node_ids_refines", '<pre>' . print_r( $selVals_node_ids_refines, true) . '</pre>');  
 }


  // $selVals_node_ids_titles = taxonomy_select_nodes($selVals_node_ids_refines);
  //     watchdog("selVals_node_ids_titles", '<pre>' . print_r( $selVals_node_ids_titles, true) . '</pre>');


    $node_title_each[] = node_load_multiple(array(),array('nid'=> $selVals_node_ids_refines));
    watchdog("node_title_each", '<pre>' . print_r( $node_title_each, true) . '</pre>');
   // $node = node_load(array('title' => 'node title'));

 $arg9090 = arg();
$query9090 = db_select('node','n');
$query9090->join('taxonomy_index','ti','n.nid=ti.nid');
// $query9090->fields('n', array('nid', 'title'))
  // ->condition('n.type', 'your_content_type_machine_name')
  // ->condition('ti.tid', $arg['2']);
$result_of_new_9090 = $query9090->execute()->fetchObject();
    watchdog("result_of_new_9090", '<pre>' . print_r( $result_of_new_9090, true) . '</pre>');

//do dsm($result); if you have devel module enabled.




   // $node_tit_bdquery = db_query("SELECT title FROM {node}  WHERE nid = :nid ", array(":nid"=> $selVals_node_ids_refines));  
   // watchdog("node_tit_bdquery", '<pre>' . print_r( $node_tit_bdquery, true) . '</pre>');








   // foreach ($selVals_node_ids_refines as  $selVals_node_ids_refine) {
   //  $node902 = node_load($selVals_node_ids_refine,null,true);
   //  watchdog("node902", '<pre>' . print_r( $node902, true) . '</pre>');
   //  $title_node2[] = $node902->title;
   //  watchdog("title_node2", '<pre>' . print_r( $title_node2, true) . '</pre>');
   // }




   }
   function dropdown_onclick_function($form, &$form_state){
   	  // $selVals =  array();
   	  // $selVals= $form['voco_types']['#options'][$form_state['values']['voco_types']];
   	  $selVals= $form_state['values']['voco_types'];
      watchdog("selVals", '<pre>' . print_r( $selVals, true) . '</pre>');

       $pppp =  taxonomy_vocabulary_machine_name_load('selVals');
       watchdog("pppp", '<pre>' . print_r( $pppp, true) . '</pre>');

       // select the termid for the using the same func for the vocabulary
       // $eeee = taxonomy_get_term('selVals');
       // watchdog("eeee", '<pre>' . print_r( $eeee, true) . '</pre>');
       //******************************
      // $need_tid = db_query("SELECT tid FROM {taxonomy_term_data} WHERE name = :name", array(':name' =>$selVals));
      // $results = mysql_query("SELECT * FROM sidemenu WHERE `menu_id`='".$menu."' ORDER BY `id` ASC LIMIT 1", $con);

    ////////
       $nid = '15';
       $node = node_load($nid);
       $title = $node;
      watchdog("title", '<pre>' . print_r( $node, true) . '</pre>');

///////

   $vocabulary_id= db_query('SELECT vid FROM {taxonomy_vocabulary} WHERE name = :name', array(':name' =>$selVals))->fetchObject();
   watchdog("vocabulary_id", '<pre>' . print_r( $vocabulary_id, true) . '</pre>');
   watchdog("vocabulary_id->vid", '<pre>' . print_r( $vocabulary_id->vid, true) . '</pre>');



  $term_id_finals_fetch = db_query("SELECT name FROM {taxonomy_term_data} WHERE vid = :vid", array(':vid' =>$vocabulary_id->vid))->fetchAll();

 watchdog("term_id_finals_fetch", '<pre>' . print_r( $term_id_finals_fetch, true) . '</pre>');
 $terms_name = array();
 foreach ($term_id_finals_fetch as $term_id_final) {
    $terms_name[$term_id_final->name] = $term_id_final->name;
      watchdog("terms_name", '<pre>' . print_r( $terms_name, true) . '</pre>');

 }


       // $need_tid = db_query("SELECT vid FROM {taxonomy_vocabulary} WHERE name = $selVals");
       // watchdog("need_tid", '<pre>' . print_r( $need_tid, true) . '</pre>');

      // json_encode($selVals);

   // $term_get_new_func =  taxonomy_get_term_by_name('$selVals');
   // $term_get_new_func_singlr = reset($term_get_new_func);
   // watchdog("term_get_new_func_singlr", '<pre>' . print_r( $term_get_new_func_singlr, true) . '</pre>');
      // $term_name= $terms_sels->name;
      // $term_querys = db_query("SELECT name FROM {taxonomy_term_data}")->fetchAll();     
      //   // $term_querys = db_query("SELECT name FROM {taxonomy_term_data}")->execute()->fetchRow();
      //   foreach ($term_querys as $term_query => $rum) {
      //   $list_of_nodes[] =  $rum->name;
      //   }
      //  watchdog("list_of_nodes", '<pre>' . print_r( $list_of_nodes, true) . '</pre>');
    

      $terms_sels = entity_load('taxonomy_term', FALSE, array('vid' => $selVals));
   	  foreach ($terms_sels as $key => $terms_sel) {
      $final_taxo[] =   $terms_sel->name;
   	  }
      watchdog("final_taxo", '<pre>' . print_r( $final_taxo, true) . '</pre>');


        //   $vacobulary_alters = taxonomy_vocabulary_load(variable_get('forum_nav_vocabulary',0));
        //  foreach ($vacobulary_alters as $key => $vacobulary_alter) {
        //   watchdog(" dhansekaran-banu", '<pre>' . print_r( $vacobulary_alter, true) . '</pre>');
        // }

   	    // $form['taxo']['terms_types']['#options'] = $final_taxo;
        $form['taxo']['terms_types']['#options'] = $terms_name;

        return $form['taxo']['terms_types'];
}

  //  function _first_dropdown_option(){
  //   //drupal map assoicate array('String'=>'String')
  //   return drupal_map_assoc(array(t('Honda'),t('toyato'),t('carola')));
  // }





 function my_content_page(){


 }
